class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), hold = -prices[0], free = 0;
        
        for (int i = 1; i < n; ++i){
            int tmp = hold;
            hold = max(hold, free - prices[i]);
            free = max(free, tmp + prices[i] - fee);
        }
        
        return free;
    }
};