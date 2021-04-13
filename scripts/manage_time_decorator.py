import functools
import time


def time_working(func):
    """Print the runtime of the decorated function"""
    @functools.wraps(func)
    def wrapper_time_working(*args, **kwargs):
        time_start = time.time()
        value = func(*args, **kwargs)
        time_end = time.time()
        print(f"{func.__name__!r} working {time_end - time_start} seconds")
        print(f"and return: {value}")
        return value
    return wrapper_time_working


@time_working
def accumulator(number):
    for _ in range(number):
        result = sum([i ** 2 for i in range(10000)])
    return result


accumulator(500)
