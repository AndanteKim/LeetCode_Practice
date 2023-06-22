class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> holds(n, 0), frees(n, 0);
        holds[0] = -prices[0];
        for (int i = 1; i < n; ++i){
            holds[i] = max(holds[i - 1], frees[i - 1] - prices[i]);
            frees[i] = max(frees[i - 1], holds[i - 1] + prices[i] - fee);
        }
        
        return frees.back();
    }
};