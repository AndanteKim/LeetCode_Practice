class Solution {
private:
    int n;
    int dp(int i, int left, vector<int>& prices, vector<vector<int>>& memo){
        // Base case
        if (i == n || left == 0) return 0;
        
        // If we saved the subproblem result
        if (memo[i][left] != -1) return memo[i][left];
        
        // start choosing no transaction
        int profit1 = dp(i + 1, left, prices, memo);
        int profit2;
        
        // Choose buying or selling it
        bool buy = (left % 2 == 0);
        if (buy)
            profit2 = -prices[i] + dp(i + 1, left - 1, prices, memo);
        else
            profit2 = prices[i] + dp(i + 1, left - 1, prices, memo);
        
        return memo[i][left] = max(profit1, profit2);
    }
    
public:
    int maxProfit(vector<int>& prices) {
        // Top-Down dynamic programming
        this -> n = prices.size();
        vector memo(n, vector<int>(5, -1));
        
        return dp(0, 4, prices, memo);
    }
};