class Solution {
private:
    int dp(int i, vector<int>& memo){
        if (i < 0) return 0;
        if (i == 0) return 1;
        if (memo[i] != -1) return memo[i];
        return memo[i] = dp(i - 1, memo) + dp(i - 2, memo);
    }
    
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        memo[0] = 0, memo[1] = 1;
        
        return dp(n, memo);
    }
};