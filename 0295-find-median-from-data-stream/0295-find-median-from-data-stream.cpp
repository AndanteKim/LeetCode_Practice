class MedianFinder {
    priority_queue<int> minH;
    priority_queue<int, vector<int>, greater<int>> maxH;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxH.push(num);
        minH.push(maxH.top());
        maxH.pop();
        if (minH.size() > maxH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if (maxH.size() > minH.size()) return (double)maxH.top();
        return (double)(minH.top() + maxH.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */