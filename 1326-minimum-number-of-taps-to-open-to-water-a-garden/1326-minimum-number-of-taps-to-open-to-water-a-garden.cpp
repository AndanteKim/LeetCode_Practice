class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Define infinite values with vector
        vector<int> dp(n + 1, 1e9);
        
        // Initialize the starting position of the garden
        dp[0] = 0;
        
        for (int i = 0; i <= n; ++i){
            // Calculate the leftmost position and rightmost position reachable by the current tap
            int start = max(0, i - ranges[i]), end = min(n, i + ranges[i]);
            
            for (int j = start; j <= end; ++j){
                // Update with the minimum number of taps
                dp[end] = min(dp[end], dp[j] + 1);
            }
        }
        
        // check if the water garden can be watered completely
        return dp[n] == 1e9? -1: dp[n];
    }
};