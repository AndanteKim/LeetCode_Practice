class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1'000'000'007;
        arrLen = min(arrLen, steps);
        vector<int> dp(steps + 1), prevDp(steps + 1);
        prevDp[0] = 1;
        
        for (int remain = 1; remain <= steps; ++remain){
            dp = vector<int>(steps + 1);
            for (int curr = arrLen - 1; curr >= 0; --curr){
                int ans = prevDp[curr];
                if (curr > 0)
                    ans = (ans + prevDp[curr - 1]) % mod;
                if (curr < arrLen - 1)
                    ans = (ans + prevDp[curr + 1]) % mod;
                dp[curr] = ans;
            }
            prevDp = dp;
        }
        
        return dp[0];
    }
};