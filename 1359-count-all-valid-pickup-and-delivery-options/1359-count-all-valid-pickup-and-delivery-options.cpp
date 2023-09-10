typedef long long ll;

class Solution {
private:
    const int MOD = 1'000'000'007;
    ll totalWays(int unpicked, int undelivered, vector<vector<int>>& dp){
        if (unpicked == 0 && undelivered == 0) return 1;
        if (unpicked < 0 || undelivered < 0 || unpicked > undelivered)
            return 0;
        
        if (dp[unpicked][undelivered] != -1)
            return dp[unpicked][undelivered];
        
        ll ans = unpicked * totalWays(unpicked - 1, undelivered, dp);
        ans %= MOD;
        
        ans = (ans + (undelivered - unpicked) * totalWays(unpicked, undelivered - 1, dp)) % MOD;
        ans %= MOD;
        return dp[unpicked][undelivered] = ans;
    }
    
public:
    int countOrders(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return totalWays(n, n, dp);
    }
};