class Solution {
private:
    int n;
    int dp(int i, int remain, vector<vector<int>>& memo, vector<int>& coins){
        if (remain == 0) return 1;
        if (i == this -> n) return 0;
        if (memo[i][remain] != -1) return memo[i][remain];
        
        if (coins[i] > remain)
            memo[i][remain] = dp(i + 1, remain, memo, coins);
        else
            memo[i][remain] = dp(i, remain - coins[i], memo, coins) + dp(i + 1, remain, memo, coins);
            
        return memo[i][remain];
    }
    
public:
    int change(int amount, vector<int>& coins) {
        this -> n = coins.size();
        vector<vector<int>> memo(this -> n, vector<int> (amount + 1, -1));
        
        return dp(0, amount, memo, coins);
    }
};