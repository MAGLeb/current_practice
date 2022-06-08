from core.trader import Trader
from core.dataclass import ClientType

if __name__ == "__main__":
    first_token = 'AVAX'
    second_token = 'USDT'
    token = 'AVAXUSDT'
    test_net = False
    Trader(first_token, second_token, token, ClientType.bybit, test_net)
