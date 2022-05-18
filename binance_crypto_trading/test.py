import pandas as pd
from bokeh.plotting import figure, ColumnDataSource, show
from bokeh.models.widgets import Dropdown
from bokeh.io import curdoc
from bokeh.layouts import column

from bokeh.models import BooleanFilter, CDSView, Select, Range1d, HoverTool
from bokeh.palettes import Category20
from bokeh.models.formatters import NumeralTickFormatter
from binance.spot import Spot as Client

from utils import floating_average, convert_to_datetime, create_column_data_source


API_KEY = "DnwcF34Sg2QaRcTskn9L35zudW3hXITkIpp47FXvMRzPeay49i9BmypRBod5xFlf"
SECRET_KEY = "DA1apmOA9jzvR1NoeAtdFeQRtb5f7lu8pGEKyiiT8jH9QLGRF2G6b218HmQtLbmu"
client = Client(API_KEY, SECRET_KEY)
data = client.klines("AVAXUSDT", interval="30m", limit=1000)
print(len(data))

df = pd.DataFrame(data, columns=["Date", "Open", "High", "Low", "Close", "Volume", "close_time", "quote_asset_volume", "number_of_trades", "taker_buy_base", "taker_buy_quote", "ignore"])
df["Date"] = df["Date"].apply(convert_to_datetime)
df.drop(["quote_asset_volume", "taker_buy_quote", "taker_buy_base", "number_of_trades", "ignore", "close_time"], inplace=True, axis=1)

# plot basic stock prices
def plot_stock_price(stock):
    p = figure(plot_width=W_PLOT, plot_height=H_PLOT, tools=TOOLS,
               title="Stock price", toolbar_location='above')

    inc = stock.data['Close'] > stock.data['Open']
    dec = stock.data['Open'] > stock.data['Close']
    view_inc = CDSView(source=stock, filters=[BooleanFilter(inc)])
    view_dec = CDSView(source=stock, filters=[BooleanFilter(dec)])

    p.segment(x0='index', x1='index', y0='Low', y1='High', color=RED, source=stock, view=view_inc)
    p.segment(x0='index', x1='index', y0='Low', y1='High', color=GREEN, source=stock, view=view_dec)

    p.vbar(x='index', width=VBAR_WIDTH, top='Open', bottom='Close', fill_color=BLUE, line_color=BLUE,
           source=stock,view=view_inc, name="price")
    p.vbar(x='index', width=VBAR_WIDTH, top='Open', bottom='Close', fill_color=RED, line_color=RED,
           source=stock,view=view_dec, name="price")

    p.legend.location = "top_left"
    p.legend.border_line_alpha = 0
    p.legend.background_fill_alpha = 0
    p.legend.click_policy = "mute"

    return p



# Define constants
W_PLOT = 1500
H_PLOT = 600
TOOLS = 'pan,wheel_zoom,reset'

VBAR_WIDTH = 0.2
RED = Category20[7][6]
GREEN = Category20[5][4]
BLUE = Category20[3][0]
BLUE_LIGHT = Category20[3][1]
ORANGE = Category20[3][2]
PURPLE = Category20[9][8]
BROWN = Category20[11][10]

tmp_data = {c: v.values for c, v in df.items()}
new_data = {}
for k, v in tmp_data.items():
    new_data[k] = v
stock = ColumnDataSource(
    data=new_data)
elements = list()

# update_plot()
p_stock = plot_stock_price(stock)

elements.append(p_stock)

curdoc().add_root(column(elements))
curdoc().title = 'Bokeh stocks historical prices'
