class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Bottom-up Dynamic programming
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for (int coin : coins){
            for (int curr = coin; curr <= amount; ++curr)
                dp[curr] = min(dp[curr], dp[curr - coin] + 1);
        }
        
        return (dp[amount] == amount + 1)? -1 : dp[amount];
    }
};