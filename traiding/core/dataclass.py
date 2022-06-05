import enum
from typing import Union
from dataclasses import dataclass


class TypeBargainSellBuy(enum.Enum):
    sell = 'Sell'
    buy = 'Buy'


class TypeBargainShortLong(enum.Enum):
    short = 'short'
    long = 'long'


class ClientType(enum.Enum):
    binance = 'binance'
    bybit = 'bybit'


@dataclass
class StateBargain:
    opened: bool
    order_id: Union[int, None]
    price_bought: Union[float, None]
    type_bargain: Union[TypeBargainShortLong, None]

    def __init__(self):
        self.opened = False
        self.order_id = None
        self.price_bought = None
        self.type_bargain = None
