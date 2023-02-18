class MovingAverage {
    int current = 0, capacity;
    long long total = 0;
    queue<int> q;
    
public:
    MovingAverage(int size) {
        capacity = size;
    }
    
    double next(int val) {
        if (current < capacity){
            ++current;
            total += val;
            q.push(val);
            return (double) total / current;
        }
        else{
            total -= q.front();
            q.pop();
            q.push(val);
            total += val;
            return (double) total / current;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */