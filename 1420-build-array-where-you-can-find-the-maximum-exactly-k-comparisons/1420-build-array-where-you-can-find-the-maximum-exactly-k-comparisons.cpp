typedef long long ll;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        ll dp[n + 1][m + 1][k + 1];
        ll prefix[n + 1][m + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        memset(prefix, 0, sizeof(prefix));
        int MOD = 1e9 + 7;
        
        for (int num = 1; num <= m; ++num){
            dp[1][num][1] = 1;
            prefix[1][num][1] = prefix[1][num - 1][1] + 1;
        }
        
        for (int i = 1; i <= n; ++i){
            for (int maxNum = 1; maxNum <= m; ++maxNum){
                for (int cost = 1; cost <= k; ++cost){
                    ll ans = (maxNum * dp[i - 1][maxNum][cost]) % MOD;
                    ans = (ans + prefix[i - 1][maxNum - 1][cost - 1]) % MOD;
                    
                    dp[i][maxNum][cost] += ans;
                    dp[i][maxNum][cost] %= MOD;
                    
                    prefix[i][maxNum][cost] = (prefix[i][maxNum - 1][cost] + dp[i][maxNum][cost]);
                    prefix[i][maxNum][cost] %= MOD;
                }
            }
        }
        
        return prefix[n][m][k];
    }
};