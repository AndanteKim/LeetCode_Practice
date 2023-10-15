class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1e9 + 7;
        arrLen = min(steps, arrLen);
        vector dp(arrLen, vector<int>(steps + 1));
        dp[0][0] = 1;
        
        for (int remain = 1; remain <= steps; ++remain){
            for (int curr = arrLen - 1; curr >= 0; --curr){
                int ans = dp[curr][remain - 1];
                
                if (curr > 0)
                    ans = (ans + dp[curr - 1][remain - 1]) % mod;
                if (curr < arrLen - 1)
                    ans = (ans + dp[curr + 1][remain - 1]) % mod;
                dp[curr][remain] = ans;
            }
        }
        
        return dp[0][steps];
    }
};