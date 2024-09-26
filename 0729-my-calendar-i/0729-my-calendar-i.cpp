class MyCalendar {
private:
    vector<pair<int, int>> calendar;

public:
    MyCalendar() {}
    
    // Brute Force
    bool book(int start, int end) {
        for (auto& [s, e] : calendar){
            // No overlapping: end2 <= start1 or end1 <= start2
            if (!(end <= s || e <= start))
                return false;
        }
        
        calendar.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */