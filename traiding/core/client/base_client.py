from typing import Union
from abc import abstractmethod

from core.dataclass import TypeBargainSellBuy


class ClientBase:
    def __init__(self, api_key, secret_key, test_net=False):
        self._api_key = api_key
        self._secret_key = secret_key
        self.api = None

        if test_net:
            self._initialise_testnet_api_client()
        else:
            self._initialise_api_client()

        self._check_api_correctness()

    @abstractmethod
    def _check_api_correctness(self):
        pass

    @abstractmethod
    def _initialise_testnet_api_client(self):
        pass

    @abstractmethod
    def _initialise_api_client(self):
        pass

    @abstractmethod
    def place_order(self, coin: str, quantity: Union[float, int], sell_or_buy: TypeBargainSellBuy):
        pass

    @abstractmethod
    def price_in_order(self, order_id: int):
        pass
