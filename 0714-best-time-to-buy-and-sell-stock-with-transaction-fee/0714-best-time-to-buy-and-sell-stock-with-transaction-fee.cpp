class Solution {
private:
    int n, fee;
    int dp(int i, int j, vector<int>& prices, vector<vector<int>>& memo){
        if (i >= n)
            return 0;
        
        if (memo[i][j] != -1)
           return memo[i][j];
        
        int profit = 0;
        if (j == 0)
            profit = max(-prices[i] + dp(i + 1, 1, prices, memo), dp(i + 1, 0, prices, memo));
        else
            profit = max(prices[i] - fee + dp(i + 1, 0, prices, memo), dp(i + 1, 1, prices, memo));
            
        return memo[i][j] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices, int fee) {
        this -> n = prices.size(), this -> fee = fee;
        vector memo(n, vector<int>(2, -1));
        return dp(0, 0, prices, memo);
    }
};