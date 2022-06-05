from binance.client import Client as BinanceClient

from base_client import ClientBase


class Binance(ClientBase):
    def __init__(self, api_key, secret_key, test_net=False):
        super().__init__(api_key, secret_key, test_net)

    def _initialise_testnet_api_client(self):
        raise "Did not implement session for Test Net."

    def _initialise_api_client(self):
        self.api = BinanceClient(self._api_key, self._secret_key)

    def _check_api_correctness(self):
        pass

    def get_current_price(self, symbol):
        return self.api.get_recent_trades(symbol=symbol, limit=1)[0]['price']

    def price_in_order(self, order_id: int):
        pass