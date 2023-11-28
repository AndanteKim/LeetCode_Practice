class Solution {
public:
    int numberOfWays(string corridor) {
        const int n = corridor.size(), MOD = 1e9 + 7;
        vector<int> prevDp(3);
        prevDp[2] = 1;
        
        for (int i = n - 1; i >= 0; --i){
            vector<int> dp(3);
            if (corridor[i] == 'S'){
                dp[0] = prevDp[1];
                dp[1] = prevDp[2];
                dp[2] = prevDp[1];
            }
            else{
                dp[0] = prevDp[0];
                dp[1] = prevDp[1];
                dp[2] = (prevDp[0] + prevDp[2]) % MOD;
            }
            prevDp = dp;
        }
        
        return prevDp[0];
    }
};