class Solution {
private:
    int dp(int start, int remain, vector<int>& memo){
        if (remain <= 0 || remain < start * start)
            return remain == 0? 0:10'001;
        
        if (memo[remain] != -1)
            return memo[remain];
        
        int ways = min(1 + dp(start, remain - start * start, memo), min(1 + dp(start + 1, remain - start * start, memo), dp(start + 1, remain, memo)));
        
        return memo[remain] = ways;
    }
    
public:
    int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        
        return dp(1, n, memo);
    }
};