from datetime import datetime
from typing import List
import numpy as np

a = [1, 11, 4, 5, 6, 7, 8, 2, 3, 4, 5, 6, 2, 3, 4, 5, 1, 2, 2, 2, 3, 4, 5, 2, 3, 4, 5]
print(np.mean(a))


def convert_to_datetime(timestamp: int):
    timestamp = int(str(timestamp)[:-3])
    return datetime.fromtimestamp(timestamp)


def floating_average(array: List, window_size: int):
    return [np.mean(array[i - window_size:i]) for i in range(window_size, len(array))]
