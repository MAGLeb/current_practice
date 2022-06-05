import time
import datetime

from client.bybit_client import ByBit
from utils import create_dataframe_from_data
from constants import BYBIT_TESTNET_API_KEY, BYBIT_TESTNET_SECRET_KEY
from dataclass import ClientType, StateBargain, TypeBargainSellBuy, TypeBargainShortLong


class Trader:
    def __init__(self, f_token, s_token, full_token, client_name: ClientType):
        self.f_token = f_token
        self.s_token = s_token
        self.token = full_token
        self.client_name = client_name

        self.prev_time = None
        self.last_open_date = None
        self.add_new_period = False

        self.state_bargain = StateBargain()
        self.historical_df = self._load_historical_data()

        self.client = ByBit(BYBIT_TESTNET_API_KEY, BYBIT_TESTNET_SECRET_KEY, test_net=True)

    def _loop(self):
        self.prev_time = int(datetime.datetime.now().timestamp() / 60) * 60
        self.last_open_date = self.historical_df.iloc[-1]['Date'].timestamp()

        while True:
            time.sleep(15)
            current_time = datetime.datetime.now().timestamp()

            if current_time - self.prev_time >= 60:
                self.prev_time = int(current_time / 60) * 60
                self.refresh_data()

                white_1 = self.historical_df['Low'].ewm(span=190).mean()
                white_2 = self.historical_df['High'].ewm(span=190).mean()
                red_1 = self.historical_df['Low'].ewm(span=210).mean()
                red_2 = self.historical_df['High'].ewm(span=210).mean()
                yellow = self.historical_df['Close'].ewm(span=100).mean()
                mN = min([white_2.iloc[-1], white_1.iloc[-1], red_2.iloc[-1], red_1.iloc[-1]])
                mX = max([white_2.iloc[-1], white_1.iloc[-1], red_2.iloc[-1], red_1.iloc[-1]])

                if self.state_bargain.type_bargain is None:
                    self.find_type_of_bargain(mN, mX, yellow, white_1, white_2, red_1, red_2)
                elif self.state_bargain.opened:
                    self.sell_stocks(mN, mX)
                elif self.state_bargain.type_bargain is not None:
                    self.buy_stocks(mN, mX, yellow)

    def _load_historical_data(self):
        if self.client_name == ClientType.bybit:
            historical_data = self.client.api.query_kline(symbol=self.token, interval="30m", limit=1000)
            historical_df = create_dataframe_from_data(historical_data['result'], ClientType.bybit)
            historical_df.drop(historical_df.tail(1).index, inplace=True)
        else:
            raise f"We don't support right now {self.client_name}."

        return historical_df

    def refresh_data(self):
        current_data = self.client.api.query_kline(symbol=self.token, interval="1m", limit=31)
        current_df = create_dataframe_from_data(current_data, ClientType.bybit)
        current_df = current_df[current_df['Date'].apply(lambda x: x.timestamp()) >= self.last_open_date]

        if current_df.iloc[-1]['Date'].timestamp() - self.last_open_date >= 1800:
            current_df.drop(current_df.tail(1).index, inplace=True)
            self.add_new_period = True

        high = current_df['High'].max()
        low = current_df['Low'].min()
        volume = current_df['Volume'].sum()
        open_date = current_df.iloc[0]['Date']
        close_date = current_df.iloc[-1]['DateClose']
        open_cost = current_df.iloc[0]['Open']
        close_cost = current_df.iloc[-1]['Close']
        diff = close_cost - open_cost
        color = 'green' if diff >= 0 else 'red'

        if self.add_new_period:
            self.add_new_period = False
            self.last_open_date += 1800
            self.historical_df.drop(self.historical_df.head(1).index, inplace=True)
            self.historical_df.reset_index(drop=True, inplace=True)
            self.historical_df.loc[len(self.historical_df)] = [open_date, open_cost, high, low, close_cost, volume,
                                                               close_date,
                                                               diff, color]

    def find_type_of_bargain(self, mN, mX, yellow, white_1, white_2, red_1, red_2):
        if mN <= yellow.iloc[-1] <= mX:
            for i in range(len(yellow) - 1, 0, -1):
                mN = min([white_2.iloc[i], white_1.iloc[i], red_2.iloc[i], red_1.iloc[i]])
                mX = max([white_2.iloc[i], white_1.iloc[i], red_2.iloc[i], red_1.iloc[i]])
                if yellow.iloc[i] < mN:
                    self.state_bargain.type_bargain = TypeBargainShortLong.long
                    break
                elif yellow.iloc[i] > mX:
                    self.state_bargain.type_bargain = TypeBargainShortLong.short
                    break

    def buy_stocks(self, mN, mX, yellow):
        if mN >= yellow.iloc[-1] or yellow.iloc[-1] >= mX:
            if self._do_cancel_bargain(mN, mX, yellow):
                self.state_bargain.type_bargain = None
            else:
                free_second_token = self.client.get_current_balance_coin(self.s_token)
                self.state_bargain.order_id = self.client.place_order(self.token, free_second_token,
                                                                      TypeBargainSellBuy.buy)
                self.state_bargain.price_bought = self.client.price_in_order(self.state_bargain.order_id)
                self.state_bargain.opened = True

    def _do_cancel_bargain(self, mN, mX, yellow):
        expression_1 = yellow.iloc[-1] >= mX and self.state_bargain.type_bargain == TypeBargainShortLong.short
        expression_2 = yellow.iloc[-1] <= mN and self.state_bargain.type_bargain == TypeBargainShortLong.long
        return expression_1 or expression_2

    def sell_stocks(self, mN, mX):
        if self._do_sell_stocks(mN, mX):
            free_first_token = self.client.get_current_balance_coin(self.f_token)
            self.client.place_order(self.token, free_first_token, TypeBargainSellBuy.sell)
            self.state_bargain = StateBargain()

    def _do_sell_stocks(self, mN, mX):
        close_cost = self.historical_df.iloc[-1]['Close']
        expression_1 = self.state_bargain.type_bargain == TypeBargainShortLong.short and close_cost >= mN
        expression_2 = self.state_bargain.type_bargain == TypeBargainShortLong.long and close_cost <= mX
        expression_3 = abs(close_cost - self.state_bargain.price_bought) > mX - mN
        return expression_1 or expression_2 or expression_3
