class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;
    
public:
    MedianFinder() : lo_median(data.end()), hi_median(data.end()) {
        
    }
    
    void addNum(int num) {
        const size_t n = data.size();
        data.insert(num);
        
        if (!n){
            lo_median = hi_median = data.begin();
        }
        else if (n & 1){
            if (num < *lo_median) --lo_median;
            else ++hi_median;
        }
        else{
            if (num > *lo_median && num < *hi_median){
                ++lo_median;
                --hi_median;
            }
            else if (num >= *hi_median) ++lo_median;
            else lo_median = --hi_median;
        }
    }
    
    double findMedian() {
        return ((double) *lo_median + *hi_median) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */