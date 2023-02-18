class Logger:

    def __init__(self):
        self._logs = dict()

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message not in self._logs:
            self._logs[message] = timestamp
            return True
        
        if timestamp - self._logs[message] >= 10:
            self._logs[message] = timestamp
            return True
        else:
            return False


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)