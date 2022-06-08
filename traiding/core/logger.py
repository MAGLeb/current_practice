import logging


class Logger:
    def __init__(self):
        self.logger = logging.getLogger("CUSTOM LOGGER")
        self._setup()

    def info(self, message):
        self.logger.info(message)

    def _setup(self):
        self.logger.setLevel(logging.DEBUG)

        info_handler = logging.FileHandler('info.log')
        info_handler.setLevel(logging.INFO)
        info_handler.setFormatter(logging.Formatter('%(asctime)s - %(message)s'))
        info_handler.addFilter(CustomLoggerFilter(logging.INFO))

        exception_handler = logging.FileHandler('exception.log')
        exception_handler.setLevel(logging.WARNING)
        exception_handler.setFormatter(logging.Formatter('%(asctime)s - %(message)s'))

        self.logger.addHandler(info_handler)
        self.logger.addHandler(exception_handler)


class CustomLoggerFilter(logging.Filter):
    def __init__(self, level):
        super().__init__()
        self._level = level

    def filter(self, logRecord):
        return logRecord.levelno <= self._level
