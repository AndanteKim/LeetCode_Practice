class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Bottom-up dynamic programming
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5));
        
        for (int i = n; i >= 0; --i){
            for (int left = 0; left <= 4; ++left){
                // Base case
                if (left == 0 || i == n)
                    dp[i][left] = 0;
                else{
                    // Choice 1: No transaction day
                    int profit1 = dp[i + 1][left], profit2 = 0;
                    
                    // Choice 2: transaction day
                    bool buy = (left % 2 == 0);
                    if (buy)
                        profit2 = -prices[i] + dp[i + 1][left - 1];
                    else
                        profit2 = prices[i] + dp[i + 1][left - 1];
                    dp[i][left] = max(profit1, profit2);
                }
            }
        }
        
        return dp[0][4];
    }
};