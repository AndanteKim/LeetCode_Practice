class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1);
        
        for (int start = n - 1; start >= 0; --start){
            int end = min(n, start + k), currMax = 0;
            
            for (int i = start; i < end; ++i){
                currMax = max(currMax, arr[i]);
                
                // Store the maximum of all options for the current subarray.
                dp[start] = max(dp[start], currMax * (i - start + 1) + dp[i + 1]);
            }
        }
        
        return dp[0];
    }
};