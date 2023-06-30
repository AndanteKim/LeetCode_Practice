class Solution {
private:
    int n;
    int dp(int i, int holding, int remain, vector<int>& prices, vector<vector<vector<int>>>& memo){
        if (i == n || remain == 0) return 0;
        if (memo[i][holding][remain] != -1){
            return memo[i][holding][remain];
        }
        
        int ans = dp(i + 1, holding, remain, prices, memo);
        if (holding == 1){
            ans = max(ans, prices[i] + dp(i + 1, 0, remain - 1, prices, memo));
        }
        else{
            ans = max(ans, -prices[i] + dp(i + 1, 1, remain, prices, memo));
        }
        
        memo[i][holding][remain] = ans;
        return ans;
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        this -> n = prices.size();
        vector<vector<vector<int>>> memo(n + 1, vector(2, vector(k + 1, -1)));
        return dp(0, 0, k, prices, memo);
    }
};