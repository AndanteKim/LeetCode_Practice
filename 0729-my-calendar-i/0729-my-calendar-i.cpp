class MyCalendar {
private:
    set<pair<int, int>> calendar;
    
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        const pair<int, int> event{start, end};
        const set<pair<int, int>>::iterator nextEvent = calendar.lower_bound(event);
        if (nextEvent != calendar.end() && nextEvent -> first < end)
            return false;
        
        if (nextEvent != calendar.begin()){
            const set<pair<int, int>>::iterator prevEvent = prev(nextEvent);
            if (prevEvent -> second > start) return false;
        }
        
        calendar.insert(event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */