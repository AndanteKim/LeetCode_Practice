class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int n = nums.size();
        
        // Sort pair (num, i) by min heap
        for (int i = 0; i < n; ++i)
            minHeap.push({nums[i], i});
        
        // Start k operations as a simulation
        for (int i = 0; i < k; ++i){
            auto [num, idx] = minHeap.top(); minHeap.pop();
            minHeap.push({num * multiplier, idx});
        }
        
        // reorganize multiplied number for each index
        vector<int> ans(n);
        while (!minHeap.empty()){
            auto [num, idx] = minHeap.top(); minHeap.pop();
            ans[idx] = num;
        }
        
        return ans;
    }
};