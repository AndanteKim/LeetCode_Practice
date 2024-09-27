class MyCalendarTwo {
private:
    // Store the number of bookings at each point.
    map<int, int> bookingCount;
    
    // The maximum number of overlapped bookings allowed.
    int maxOverlappedBookings = 2;
    
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        // Increase and decrease the booking count at the start and end respectively.
        ++bookingCount[start];
        --bookingCount[end];
        
        int overlappedBookings = 0;
        
        // Calculate the prefix sum of bookings
        for (auto& [_, count] : bookingCount){
            overlappedBookings += count;
            
            // If the numbrer of overlaps exceeds the allowed limit
            // rollback and return false.
            if (overlappedBookings > maxOverlappedBookings){
                // Rollback changes.
                --bookingCount[start];
                ++bookingCount[end];
                
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */