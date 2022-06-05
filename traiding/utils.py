from datetime import datetime

import pandas as pd
import plotly.graph_objects as go
from plotly.subplots import make_subplots

from core.dataclass import ClientType


def convert_to_datetime(timestamp: int):
    if timestamp == 0:
        return timestamp
    timestamp = int(str(timestamp)[:-3])
    return datetime.fromtimestamp(timestamp)


def create_dataframe_from_data(data, source: ClientType):
    """
    Method to convert data from "Binance" and "ByBit" to pd.DataFrame.

    :param source: source of data
    :param data: Array
    :return: pd.DataFrame
    """
    if source == ClientType.binance:
        columns = ["Date", "Open", "High", "Low", "Close", "Volume", "DateClose", "quote_asset_volume",
                   "number_of_trades", "taker_buy_base", "taker_buy_quote", "ignore"]
    elif source == ClientType.bybit:
        columns = ["Date", "Open", "High", "Low", "Close", "Volume", "DateClose", "quote_asset_volume",
                   "number_of_trades", "taker_buy_base", "taker_buy_quote"]
    else:
        raise f"We don't support {source}."

    df = pd.DataFrame(data, columns=columns)
    df["Date"] = df["Date"].apply(convert_to_datetime)
    df["DateClose"] = df["DateClose"].apply(convert_to_datetime)
    df["Open"] = df["Open"].apply(lambda x: float(x))
    df["High"] = df["High"].apply(lambda x: float(x))
    df["Low"] = df["Low"].apply(lambda x: float(x))
    df["Close"] = df["Close"].apply(lambda x: float(x))
    df["Volume"] = df["Volume"].apply(lambda x: float(x))

    if source == ClientType.binance:
        df.drop(["quote_asset_volume", "taker_buy_quote", "taker_buy_base", "number_of_trades", "ignore"], inplace=True,
                axis=1)
    elif source == ClientType.bybit:
        df.drop(["quote_asset_volume", "taker_buy_quote", "taker_buy_base", "number_of_trades"], inplace=True, axis=1)

    df['diff'] = df['Close'] - df['Open']
    df.loc[df['diff'] >= 0, 'color'] = 'green'
    df.loc[df['diff'] < 0, 'color'] = 'red'

    return df


def plot_stocks(df: pd.DataFrame):
    """
    Plot graphic with different type of EWM's and current price.

    :param df: pd.DataFrame
    :return: show plot
    """
    fig3 = make_subplots(specs=[[{"secondary_y": True}]])
    fig3.add_trace(go.Candlestick(x=df.index,
                                  open=df['Open'],
                                  high=df['High'],
                                  low=df['Low'],
                                  close=df['Close'],
                                  name='Price'))
    fig3.add_trace(go.Scatter(x=df.index, y=df['Close'].ewm(span=100).mean(), marker_color='yellow', name='100 MA'))
    fig3.add_trace(go.Scatter(x=df.index, y=df['Close'].ewm(span=200).mean(), marker_color='blue', name='200 Day MA'))
    fig3.add_trace(
        go.Scatter(x=df.index, y=df['Low'].ewm(span=190).mean(), marker_color='green', name='190 Day, short'))
    fig3.add_trace(
        go.Scatter(x=df.index, y=df['High'].ewm(span=190).mean(), marker_color='green', name='190 Day, long'))
    fig3.add_trace(go.Scatter(x=df.index, y=df['Low'].ewm(span=210).mean(), marker_color='red', name='210 Day, short'))
    fig3.add_trace(go.Scatter(x=df.index, y=df['High'].ewm(span=210).mean(), marker_color='red', name='210 Day, long'))
    fig3.add_trace(go.Bar(x=df.index, y=df['Volume'], name='Volume', marker={'color': df['color']}), secondary_y=True)
    fig3.update_yaxes(range=[0, 700000000], secondary_y=True)
    fig3.update_yaxes(visible=False, secondary_y=True)
    fig3.update_layout(xaxis_rangeslider_visible=False)  # hide range slider
    fig3.update_layout(title={'text': 'TSLA', 'x': 0.5})
    fig3.show()
