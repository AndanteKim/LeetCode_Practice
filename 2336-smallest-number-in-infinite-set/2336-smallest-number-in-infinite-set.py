class SmallestInfiniteSet:

    def __init__(self):
        self.is_present: {int} = set()
        self.added_integers:[int] = []
        self.current_integer = 1

    def popSmallest(self) -> int:
        if len(self.added_integers):
            ans = heappop(self.added_integers)
            self.is_present.remove(ans)
        else:
            ans = self.current_integer
            self.current_integer += 1
        return ans

    def addBack(self, num: int) -> None:
        if self.current_integer <= num or num in self.is_present:
            return
        heappush(self.added_integers, num)
        self.is_present.add(num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)