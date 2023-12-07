class Solution {
private:
    int n;
    int dp(int i, int bought, vector<vector<int>>& memo, vector<int>& prices){
        if (i >= n)
            return 0;
        if (memo[i][bought] != -1)
            return memo[i][bought];
        
        int profit = 0;
        if (bought){
            profit += max(dp(i + 1, 1, memo, prices), prices[i] + dp(i + 1, 0, memo, prices));
        }
        else{
            profit += max(-prices[i] + dp(i + 1, 1, memo, prices), dp(i + 1, 0, memo, prices));
        }
        
        return memo[i][bought] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector memo(n, vector<int>(2, -1));
        return dp(0, 0, memo, prices);
    }
};