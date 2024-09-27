class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // One-pass simulation
        int t1Cost = INT_MAX, t2Cost = INT_MAX;
        int t1Profit = 0, t2Profit = 0;
        
        for (int price : prices){
            // The maximum profit if only one transaction is allowed
            t1Cost = min(t1Cost, price);
            t1Profit = max(t1Profit, price - t1Cost);
            
            // reinvest the gained profit in the second transaction 
            t2Cost = min(t2Cost, price - t1Profit);
            t2Profit = max(t2Profit, price - t2Cost);
        }
        
        return t2Profit;
    }
};