class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) minHeap.push(num);
        
        while (k > 0){
            int n = minHeap.top();
            minHeap.pop();
            minHeap.push(-n);
            --k;
        }
        
        int ans = 0;
        while (minHeap.size() > 0) {
            ans += minHeap.top();
            minHeap.pop();
        }
        
        return ans;
    }
};