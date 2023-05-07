class SeatManager:

    def __init__(self, n: int):
        self.unreserved_seats = []
        self.current = 1

    def reserve(self) -> int:
        if len(self.unreserved_seats) > 0:
            return heappop(self.unreserved_seats)
        else:
            current_counter = self.current
            self.current += 1
            return current_counter

    def unreserve(self, seatNumber: int) -> None:
        heappush(self.unreserved_seats, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)