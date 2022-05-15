import logging
from datetime import datetime
import matplotlib.pyplot as plt

from binance.spot import Spot as Client
from binance.lib.utils import config_logging
from test import floating_average, convert_to_datetime

API_KEY = "DnwcF34Sg2QaRcTskn9L35zudW3hXITkIpp47FXvMRzPeay49i9BmypRBod5xFlf"
SECRET_KEY = "DA1apmOA9jzvR1NoeAtdFeQRtb5f7lu8pGEKyiiT8jH9QLGRF2G6b218HmQtLbmu"
TEST_NET = True
# config_logging(logging, logging.DEBUG)

client = Client(API_KEY, SECRET_KEY)

# average_data = client.agg_trades("BTCUSDT", interval="30m", limit=250)
# print(len(average_data))
other_data = client.klines("BTCUSDT", interval="1m", limit=1000)
print(len(other_data))

low = []
high = []
timestamp = []

for other_ in other_data:
    open_time = convert_to_datetime(other_[0])
    close_time = convert_to_datetime(other_[6])
    low.append(float(other_[3]))
    high.append(float(other_[2]))
    timestamp.append(open_time)
    print(f"OPEN: {open_time}, CLOSE: {close_time}, LOW: {low[-1]}, HIGH: {high[-1]}")

print(low)

white_min = floating_average(low, 190)
white_max = floating_average(high, 190)
red_min = floating_average(low, 210)
red_max = floating_average(high, 210)

plt.plot(timestamp[:-190], white_min, color='green')
plt.plot(timestamp[:-190], white_max, color='green')
plt.plot(timestamp[:-210], red_min, color='red')
plt.plot(timestamp[:-210], red_max, color='red')

plt.show()
