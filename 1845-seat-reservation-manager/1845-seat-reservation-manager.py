class SeatManager:

    def __init__(self, n: int):
        self.heap, self.missing = [], []
        self.current = 1

    def reserve(self) -> int:
        if not self.missing:
            heappush(self.heap, self.current)
            self.current += 1
            return self.current - 1
        else:
            num = heappop(self.missing)
            heappush(self.heap, num)
            return num

    def unreserve(self, seatNumber: int) -> None:
        self.heap.remove(seatNumber)
        heappush(self.missing, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)