class Logger:

    def __init__(self):
        self.logs = dict()

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message not in self.logs:
            self.logs[message] = timestamp + 10
        elif timestamp < self.logs[message]:
            return False
        elif timestamp >= self.logs[message]:
            self.logs[message] = timestamp + 10
        return True


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)