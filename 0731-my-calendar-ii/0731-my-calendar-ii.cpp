class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings, overlappedBooking;
    
    // Return true if the booking [start1, end1) & [start2, end2) overlaps
    bool doesOverlapped(int start1, int end1, int start2, int end2) const{
        return !(end1 <= start2 || end2 <= start1); 
    }
    
    // Return overlapping booking between [start1, end1) & [start2, end2).
    pair<int, int> getOverlapped(int start1, int end1, int start2, int end2) const{
        return make_pair(max(start1, start2), min(end1, end2));
    }
    
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        // Base case: If the new booking overlaps with the existing double-booked bookings, return false
        for (const auto& [s, e] : overlappedBooking){
            if (doesOverlapped(s, e, start, end)) return false;
        }
        
        // Add the double overlapping if any with the new booking.
        for (const auto& [s, e] : bookings){
            if (doesOverlapped(s, e, start, end))
                overlappedBooking.push_back(getOverlapped(s, e, start, end));
        }
        
        // Add the booking to the list of bookings.
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */