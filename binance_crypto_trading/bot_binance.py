from bokeh.plotting import figure, show

from binance.spot import Spot as Client
from utils import floating_average, convert_to_datetime, create_column_data_source

API_KEY = "DnwcF34Sg2QaRcTskn9L35zudW3hXITkIpp47FXvMRzPeay49i9BmypRBod5xFlf"
SECRET_KEY = "DA1apmOA9jzvR1NoeAtdFeQRtb5f7lu8pGEKyiiT8jH9QLGRF2G6b218HmQtLbmu"
client = Client(API_KEY, SECRET_KEY)
data = client.klines("AVAXUSDT", interval="30m", limit=1000)
print(len(data))

low = []
high = []
average = []
opened = []
closed = []
timestamp = []

for data_ in data:
    open_time = convert_to_datetime(data_[0])
    close_time = convert_to_datetime(data_[6])
    low.append(float(data_[3]))
    high.append(float(data_[2]))
    average.append((low[-1] + high[-1]) / 2)
    opened.append(float(data_[1]))
    closed.append(float(data_[4]))
    timestamp.append(close_time)
    print(f"OPEN: {open_time}, CLOSE: {close_time}, LOW: {low[-1]}, HIGH: {high[-1]}")

pink = floating_average(closed, 100)
grey = floating_average(average, 100)

blue = floating_average(closed, 200)
white_min = floating_average(low, 190)
white_max = floating_average(high, 190)
red_min = floating_average(low, 210)
red_max = floating_average(high, 210)

TOOLTIPS = [
    ("(x,y)", "($x, $y)"),
]

print(timestamp[0])

graph = figure(title="Bokeh Line Graph", plot_width=1800, plot_height=700, x_axis_type="datetime", tooltips=TOOLTIPS)

# The average of three different values: opened, closed, average(high+low / 2).
graph.line('x', 'y', source=create_column_data_source(opened, timestamp, 100), color='yellow')
graph.line('x', 'y', source=create_column_data_source(closed, timestamp, 100), color='pink')
graph.line('x', 'y', source=create_column_data_source(average, timestamp, 100), color='grey')

graph.line('x', 'y', source=create_column_data_source(closed, timestamp, 1), color='black')
graph.line('x', 'y', source=create_column_data_source(closed, timestamp, 200), color='blue')
#
graph.line('x', 'y', source=create_column_data_source(low, timestamp, 190), color='green')
graph.line('x', 'y', source=create_column_data_source(high, timestamp, 190), color='green')
graph.line('x', 'y', source=create_column_data_source(low, timestamp, 210), color='red')
graph.line('x', 'y', source=create_column_data_source(high, timestamp, 210), color='red')

show(graph)
