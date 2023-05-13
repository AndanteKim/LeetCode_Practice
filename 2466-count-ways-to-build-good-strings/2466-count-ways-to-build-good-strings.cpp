class Solution {
    int mod = pow(10, 9) + 7;
    
    int dfs(int end, vector<int>& dp, int zero, int one){
        if (dp[end] != -1) return dp[end];
        int count = 0;
        if (end >= zero) count = (count + dfs(end - zero, dp, zero, one)) % mod;
        if (end >= one) count = (count + dfs(end - one, dp, zero, one)) % mod;
        dp[end] = count % mod;
        return dp[end];
    }
    
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        dp[0] = 1;
        int ans = 0;
        
        for (int end = low; end <= high; ++end){
            ans = (ans + dfs(end, dp, zero, one)) % mod;
        }
        
        return ans;
    }
};