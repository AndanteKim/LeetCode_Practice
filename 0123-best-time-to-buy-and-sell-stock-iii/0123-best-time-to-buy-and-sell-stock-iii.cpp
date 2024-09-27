class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Space-optimized dynamic programming
        int n = prices.size();
        vector<int> prevDp(5);
        
        for (int i = n; i >= 0; --i){
            vector<int> dp(5);
            for (int left = 0; left <= 4; ++left){
                if (i == n || left == 0) continue;
                
                // Choice 1: No transaction day
                int profit1 = prevDp[left];
                
                // Choice 2: Transaction day
                bool buy = (left % 2 == 0);
                int profit2 = 0;
                
                if (buy)
                    profit2 = -prices[i] + prevDp[left - 1];
                else
                    profit2 = prices[i] + prevDp[left - 1];
                
                dp[left] = max(profit1, profit2);
            }
            prevDp = dp;
        }
        
        return prevDp[4];
    }
};