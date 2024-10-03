class Solution {
public:
    int fib(int n) {
        // Base case
        if (n <= 1) return n;
        
        vector<int> dp(n + 1, 0);
        
        // Bottom-up
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 2] + dp[i - 1];
        
        return dp[n];
    }
};