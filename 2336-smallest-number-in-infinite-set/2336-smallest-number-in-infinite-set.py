class SmallestInfiniteSet:

    def __init__(self):
        self.inf_set = []
        for i in range(1, 1001):
            heappush(self.inf_set, i)

    def popSmallest(self) -> int:
        return heappop(self.inf_set)

    def addBack(self, num: int) -> None:
        if num not in self.inf_set:
            heappush(self.inf_set, num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)