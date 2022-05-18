from pybit import inverse_perpetual
from datetime import datetime
import matplotlib.pyplot as plt

from utils import floating_average, convert_to_datetime

API_KEY = "HrZH0ZeUa1wRBrFmwx"
SECRET_KEY = "OsyhuUE6vf7gfMhHBkcYbcAKOmtPz0044QmX"


session = inverse_perpetual.HTTP(
    endpoint='https://api.bybit.com',
    api_key=API_KEY,
    api_secret=SECRET_KEY
)
print(session.orderbook(symbol="BTCUSD"))