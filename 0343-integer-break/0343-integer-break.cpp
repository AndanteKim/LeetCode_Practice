class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3)
            return n - 1;
        
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        
        for (int num = 4; num <= n; ++num){
            int ans = num;
            for (int i = 2; i < num; ++i){
                ans = max(ans, i * dp[num - i]);
            }
            dp[num] = ans;
        }
        
        return dp[n];
    }
};