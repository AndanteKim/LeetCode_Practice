class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // readable space optimized dynamic programming
        int n = prices.size();
        // max_profit if I
        int hadStockYesterday = -prices[0], haveStockToday;
        
        // max_profit if I
        int didntHaveStockYesterday = 0, dontHaveStockToday;
        
        for (int price : prices){
            haveStockToday = max(hadStockYesterday, didntHaveStockYesterday - price);
            dontHaveStockToday = max(didntHaveStockYesterday, hadStockYesterday + price - fee);
            hadStockYesterday = haveStockToday;
            didntHaveStockYesterday = dontHaveStockToday;
        }
        
        return dontHaveStockToday;
    }
};