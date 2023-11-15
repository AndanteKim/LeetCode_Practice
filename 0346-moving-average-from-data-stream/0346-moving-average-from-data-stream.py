class MovingAverage:

    def __init__(self, size: int):
        self.arr, self.sum, self.capacity = deque(), 0, size

    def next(self, val: int) -> float:
        if len(self.arr) >= self.capacity:
            self.sum -= self.arr.popleft()
        self.arr.append(val)
        self.sum += val
        return self.sum / len(self.arr)
        
        

# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)