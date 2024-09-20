class Solution {
private:
    int dp(vector<int>& coins, vector<int>& count, int remain){
        // Base case
        if (remain < 0) return -1;
        if (remain == 0) return 0;
        if (count[remain - 1] != 0) return count[remain - 1];
        
        int minCoins = INT_MAX;
        for (int coin : coins){
            int res = dp(coins, count, remain - coin);
            if (0 <= res && res < minCoins)
                minCoins = res + 1;
        }
        count[remain - 1] = (minCoins == INT_MAX)? -1 : minCoins;
        
        return count[remain - 1];
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        // Base case
        if (amount < 1) return 0;
        
        // Top-down Dynamic Programming
        vector<int> count(amount, 0);
        return dp(coins, count, amount);
    }
};