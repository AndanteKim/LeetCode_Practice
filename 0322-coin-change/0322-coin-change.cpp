class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i <= amount; ++i){
            for (int coin : coins){
                if ((long)i + coin <= amount)
                    dp[i + coin] = min(dp[i] + 1, dp[i + coin]);
            }
        }
        
        return dp[amount] == INT_MAX? -1 : dp[amount];
    }
};