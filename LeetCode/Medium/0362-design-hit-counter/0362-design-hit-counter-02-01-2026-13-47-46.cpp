class HitCounter {
private:
    priority_queue<int, vector<int>, greater<>> records;

public:
    HitCounter() {}
    
    void hit(int timestamp) {
        records.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!records.empty() && records.top() <= timestamp - 300) records.pop();

        return records.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */