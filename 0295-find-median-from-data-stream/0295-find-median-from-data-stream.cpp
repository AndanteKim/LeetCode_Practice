class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator mid;
    
public:
    MedianFinder() : mid(data.end()) {
        
    }
    
    void addNum(int num) {
        const int n = data.size();
        data.insert(num);
        
        if (!n){
            mid = data.begin();
        }
        else if (num < *mid){
            mid = (n & 1? mid : prev(mid));
        }
        else{
            mid = (n & 1? next(mid) : mid);
        }
    }
    
    double findMedian() {
        const int n = data.size();
        return ((double) *mid + *next(mid, n % 2 - 1)) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */