class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 1000);
        
        // base case
        dp[1] = 0;
        for (int i = 2; i <= n; ++i){
            for (int j = 1; j <= (i >> 1); ++j){
                if (i % j == 0){
                    // Copy all and paste (i - j) / j times
                    // for all valid j's
                    dp[i] = min(dp[i], dp[j] + i / j);
                }
            }
        }
        
        return dp[n];
    }
};