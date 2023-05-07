class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int num : nums){
            if (pq.size() >= k){
                if (num >= pq.top()){
                    pq.pop();
                    pq.push(num);
                }
                continue;
            }
            pq.push(num);
        }
        
        return pq.top();
    }
};