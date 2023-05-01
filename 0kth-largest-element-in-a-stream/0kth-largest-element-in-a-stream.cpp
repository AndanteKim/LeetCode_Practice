class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int kLargest;
public:
    KthLargest(int k, vector<int>& nums) {
        kLargest = k;
        for (int num : nums) {
            if (pq.size() >= kLargest) {
                if (pq.top() <= num){
                    pq.pop();
                    pq.push(num);
                }
                continue;
            }
            pq.push(num);
        }
    }
    
    int add(int val) {
        if (pq.size() >= kLargest && pq.top() <= val){
            pq.pop();
            pq.push(val);
        }
        else if (pq.size() < kLargest) pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */