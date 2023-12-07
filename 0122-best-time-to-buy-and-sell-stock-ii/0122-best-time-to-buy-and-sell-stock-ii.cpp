class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n);
        for (int i = 1; i < n; ++i)
            dp[i] = dp[i - 1] + max(0, prices[i] - prices[i - 1]);
        return dp.back();
    }
};