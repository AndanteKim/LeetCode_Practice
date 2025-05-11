class Logger:

    def __init__(self):
        self.logs = dict()

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message in self.logs and self.logs[message] + 10 > timestamp:
            return False
        
        self.logs[message] = timestamp
        return True


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)