class HitCounter:

    def __init__(self):
        self.records = []

    def hit(self, timestamp: int) -> None:
        heappush(self.records, timestamp)

    def getHits(self, timestamp: int) -> int:
        while self.records[0] <= timestamp - 300:
            heappop(self.records)

        return len(self.records)


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)