class Solution {
private:
    int dp(int remain, vector<int>& memo){
        // Base case
        if (remain == 0)
            return 1;
        
        if (remain < 0) return 0;
        
        if (memo[remain] != -1)
            return memo[remain];
        
        int ways = dp(remain - 1, memo);
        ways += dp(remain - 2, memo);
        
        return memo[remain] = ways;
    }
    
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        
        return dp(n, memo);
    }
};