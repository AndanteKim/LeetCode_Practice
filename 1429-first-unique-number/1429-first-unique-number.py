class FirstUnique:

    def __init__(self, nums: List[int]):
        self.queue, self.seen = deque(), dict()
        for num in nums:
            self.add(num)

    def showFirstUnique(self) -> int:
        while self.queue and self.seen[self.queue[0]] > 1:
            self.queue.popleft()
        
        return -1 if not self.queue else self.queue[0]

    def add(self, value: int) -> None:
        if value not in self.seen:
            self.queue.append(value)
        self.seen[value] = self.seen.get(value, 0) + 1


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)