class FirstUnique:

    def __init__(self, nums: List[int]):
        self.queue, self.count = deque(), defaultdict(int)
        for num in nums:
            if num not in self.count:
                self.queue.append(num)
            self.count[num] += 1

            while self.queue and self.count[self.queue[0]] > 1:
                self.queue.popleft()

    def showFirstUnique(self) -> int:
        return -1 if not self.queue else self.queue[0]

    def add(self, value: int) -> None:
        if value not in self.count:
            self.queue.append(value)

        self.count[value] += 1
        while self.queue and self.count[self.queue[0]] > 1:
            self.queue.popleft()

# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)