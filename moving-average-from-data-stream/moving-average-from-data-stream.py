class MovingAverage:

    def __init__(self, size: int):
        self.capacity = size
        self.current = 0
        self.queue = deque()
        self.total = 0

    def next(self, val: int) -> float:
        if self.current < self.capacity:
            self.current += 1
            self.queue.append(val)
            self.total += val
            return self.total / self.current
        else:
            self.total -= self.queue.popleft()
            self.queue.append(val)
            self.total += val
            return self.total / self.current
            


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)