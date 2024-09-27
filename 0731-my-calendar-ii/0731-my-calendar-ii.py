from sortedcontainers import SortedDict

class MyCalendarTwo:
    def __init__(self):
        # Store the number of bookings at each point.
        self.booking_count = SortedDict()
        # The maximum number of overlapped bookings allowed. 
        self.max_overlapped_booking = 2

    def book(self, start: int, end: int) -> bool:
        # Increase and decrease the booking count at the start and end respectively.
        self.booking_count[start] = self.booking_count.get(start, 0) + 1
        self.booking_count[end] = self.booking_count.get(end, 0) - 1
        overlapped_booking = 0
        
        # Calculate the prefix sum of bookings
        for count in self.booking_count.values():
            overlapped_booking += count
            
            # If the number of overlaps exceeds the allowed limit
            # rollback and return False
            if overlapped_booking > self.max_overlapped_booking:
                # Rollback changes
                self.booking_count[start] -= 1
                self.booking_count[end] += 1
                
                # Remove entries if their count becomes zero to clean up the SortedDict.
                if self.booking_count[start] == 0:
                    del self.booking_count[start]
                return False
        
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)