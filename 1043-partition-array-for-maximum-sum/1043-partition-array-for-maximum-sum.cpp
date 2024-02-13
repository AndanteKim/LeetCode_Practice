class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(), K = k + 1;
        vector<int> dp(n + 1);
        
        for (int start = n - 1; start >= 0; --start){
            int currMax = 0, end = min(n, start + k);
            for (int i = start; i < end; ++i){
                currMax = max(currMax, arr[i]);
                
                // Store the maximum of all options for the current subarray
                dp[start % K] = max(dp[start % K], dp[(i + 1) % K] + (currMax * (i - start + 1)));
            }
        }
        
        return dp[0];
    }
};