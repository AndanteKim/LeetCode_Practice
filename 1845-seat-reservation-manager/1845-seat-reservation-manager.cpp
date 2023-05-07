class SeatManager {
    priority_queue<int, vector<int>, greater<int>> unreservedSeats;
    int current = 1;
public:
    SeatManager(int n) {}
    
    int reserve() {
        if (unreservedSeats.size() > 0) {
            int num = unreservedSeats.top();
            unreservedSeats.pop();
            return num;
        }
        else{
            int currentCounter = current;
            ++current;
            return currentCounter;
        }
    }
    
    void unreserve(int seatNumber) {
        unreservedSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */