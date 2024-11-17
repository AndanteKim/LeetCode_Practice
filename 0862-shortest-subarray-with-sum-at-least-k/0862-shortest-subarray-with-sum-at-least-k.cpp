class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = std::numeric_limits<int>::max();
        
        // Initialize result to the maximum possible integer value
        long cumulativeSum = 0;
        
        // Min-heap to store cumulative sum and its corresponding index
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> prefixSum;
        
        // Iterate through the array
        for (int i = 0; i < n; ++i){
            // Update cumulative sum
            cumulativeSum += nums[i];
            
            // If cumulative sum is already >= k, update the shortest length
            if (cumulativeSum >= k)
                ans = min(ans, i + 1);
            
            // Remove subarrays from heap that can form a valid subarray
            while (!prefixSum.empty() && cumulativeSum - prefixSum.top().first >= k){
                auto [_, prevIndex] = prefixSum.top();
                prefixSum.pop();
                // Update shortest subarray length
                ans = min(ans, i - prevIndex);
            }
            prefixSum.push({cumulativeSum, i});
        }
        
        // Add current cumulative sum and index to heap
        return (ans == std::numeric_limits<int>::max())? -1 : ans;
    }
};