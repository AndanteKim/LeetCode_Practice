class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = std::numeric_limits<int>::max();
        
        // Size is n + 1 to handle subarrays starting from index 0
        vector<long long> prefixSum(n + 1);
        
        // Calculate prefix sums
        for (int i = 1; i <= n; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        
        deque<int> candidateIndices;
        
        for (int i = 0; i <= n; ++i){
            // Remove candidates from front of deque where subarray sum meets target
            while (!candidateIndices.empty() && prefixSum[i] - prefixSum[candidateIndices.front()] >= k){
                // Update shortest subarray length
                ans = min(ans, i - candidateIndices.front());
                candidateIndices.pop_front();
            }
            
            // Maintain monotonicity by removing indices with larger prefix sums
            while (!candidateIndices.empty() && prefixSum[i] <= prefixSum[candidateIndices.back()])
                candidateIndices.pop_back();
            
            // Add current index to candidates
            candidateIndices.push_back(i);
        }
        
        // Return -1 if no valid subarray found
        return (ans == std::numeric_limits<int>::max())? -1 : ans; 
    }
};