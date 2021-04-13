import time


class ManagerTime:
    def __init__(self):
        self.time = 0

    def __enter__(self):
        self.start = time.time()
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.time = time.time() - self.start
        self.print()

    def print(self):
        print(self.time)


with ManagerTime() as time_function:
    i = 0
    for _ in range(10000000):
        i += 1


class Indent:
    def __init__(self):
        self.level = 0

    def __enter__(self):
        self.level += 1
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.level -= 1

    def print(self, text):
        print(' ' * self.level + text)


with Indent() as indent:
    indent.print('привет!')
    with indent:
        indent.print('здорово')
        with indent:
            indent.print('бонжур')
            indent.print('эй')
