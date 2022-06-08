import traceback
from typing import Union

from pybit.spot import HTTP as BybitClient

from core.client.base_client import ClientBase
from core.dataclass import TypeBargainSellBuy
from utils import convert_to_datetime
from constants import URL_API_BYBIT, URL_API_BYBIT_TESTNET


class ByBit(ClientBase):
    def __init__(self, api_key, secret_key, test_net=False):
        super().__init__(api_key, secret_key, test_net)

    def _initialise_testnet_api_client(self):
        self.api = BybitClient(
            endpoint=URL_API_BYBIT_TESTNET,
            api_key=self._api_key,
            api_secret=self._secret_key
        )

    def _initialise_api_client(self):
        self.api = BybitClient(
            endpoint=URL_API_BYBIT,
            api_key=self._api_key,
            api_secret=self._secret_key
        )

    def _check_api_correctness(self):
        try:
            self.get_current_balance_coin('USDT')
        except:
            print("CLIENT NOT READY TO WORK. FIRST ONE, CHECK CORRECTNESS OF API KEYS.")
            traceback.print_exc()

    def place_order(self, coin: str, quantity: Union[float, int], sell_or_buy: TypeBargainSellBuy):
        result = self.api.place_active_order(
            symbol=coin,
            side=sell_or_buy,
            type="Market",
            qty=quantity
        )
        result = result['result']
        order_id = result['orderId']
        timestamp = result['transactTime']
        symbol = result['symbol']
        qty = result['origQty']

        return order_id

    def get_current_balance_coin(self, coin: str):
        balance = self.api.get_wallet_balance()['result']['balances']
        coin_info = list(filter(lambda x: x['coin'] == coin, balance))
        if len(coin_info):
            coin_free_balance = coin_info[0]['free']
        else:
            coin_free_balance = 0
        return float(coin_free_balance)

    def price_in_order(self, order_id: int):
        return float(self.api.user_trade_records(orderId=int(order_id))['result'][0]['price'])
