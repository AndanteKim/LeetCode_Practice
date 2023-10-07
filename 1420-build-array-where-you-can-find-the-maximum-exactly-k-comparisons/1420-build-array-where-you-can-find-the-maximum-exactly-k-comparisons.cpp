typedef long long ll;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        ll dp[m + 1][k + 1], prevDp[m + 1][k + 1], prefix[m + 1][k + 1], prevPrefix[m + 1][k + 1];
        
        int MOD = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        memset(prevDp, 0, sizeof(prevDp));
        memset(prefix, 0, sizeof(prefix));
        memset(prevPrefix, 0, sizeof(prevPrefix));
        
        for (int num = 1; num <= m; ++num){
            dp[num][1] = 1;
        }
        
        for (int i = 1; i <= n; ++i){
            if (i > 1)
                memset(dp, 0, sizeof(dp));
            memset(prefix, 0, sizeof(prefix));
            
            for (int maxNum = 1; maxNum <= m; ++maxNum){
                for (int cost = 1; cost <= k; ++cost){
                    ll ans = (maxNum * prevDp[maxNum][cost]) % MOD;
                    ans = (ans + prevPrefix[maxNum -1][cost - 1]) % MOD;
                    dp[maxNum][cost] += ans;
                    dp[maxNum][cost] %= MOD;
                    
                    prefix[maxNum][cost] = (prefix[maxNum - 1][cost] + dp[maxNum][cost]);
                    prefix[maxNum][cost] %= MOD;
                }
            }
            
            // since unable reassigning long long[][] in C++, need to manually, override
            for (int maxNum = 0; maxNum <= m; ++maxNum){
                for (int cost = 0; cost <= k; ++cost){
                    prevDp[maxNum][cost] = dp[maxNum][cost];
                    prevPrefix[maxNum][cost] = prefix[maxNum][cost];
                }
            }
        }
        
        return prefix[m][k];
    }
};