class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums){
            if (minHeap.size() >= k){
                if (minHeap.top() > num)
                    continue;
                minHeap.pop();
            }
            
            minHeap.push(num);
        }
        
        return minHeap.top();
    }
};