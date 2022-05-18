from datetime import datetime
from typing import List
import numpy as np

from bokeh.models import ColumnDataSource


def create_column_data_source(array: List, timestamp: List, window_size: int):
    return ColumnDataSource(data=dict(
        x=timestamp,
        y=floating_average(array, window_size),
    ))


def convert_to_datetime(timestamp: int):
    timestamp = int(str(timestamp)[:-3])
    return datetime.fromtimestamp(timestamp)


def floating_average(array: List, window_size: int):
    return [np.mean(array[i - window_size:i]) if i >= window_size else None for i in range(0, len(array))]
