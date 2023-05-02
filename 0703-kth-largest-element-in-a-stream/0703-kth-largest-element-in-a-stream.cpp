class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for (int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        if (pq.size() >= this -> k && pq.top() <= val){
            pq.pop();
            pq.push(val);
        }
        else if (pq.size() < this -> k) pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */