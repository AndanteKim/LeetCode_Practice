class MyCalendarTwo:

    def __init__(self):
        self.bookings, self.overlap_bookings = [], []
        
    # Return True if the booking [start1, end1) & [start2, end2) overlaps.
    def does_overlap(self, start1: int, end1: int, start2: int, end2: int) -> bool:
        return max(start1, start2) < min(end1, end2)

    # Return the overlapping booking between [start1, end1) & [start2, end2).
    def get_overlapped(self, start1: int, end1: int, start2: int, end2: int) -> Tuple[int]:
        return (max(start1, start2), min(end1, end2))
    
    def book(self, start: int, end: int) -> bool:
        # Check if the new booking overlaps with any double-booked booking.
        for s, e in self.overlap_bookings:
            if self.does_overlap(s, e, start, end):
                return False
        
        # Add any new double overlaps that the current booking creates
        for s, e in self.bookings:
            if self.does_overlap(s, e, start, end):
                self.overlap_bookings.append(self.get_overlapped(s, e, start, end))
        
        # Add the new booking to the list of bookings
        self.bookings.append((start, end))
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)