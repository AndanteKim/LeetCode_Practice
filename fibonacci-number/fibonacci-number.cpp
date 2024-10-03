class Solution {
private:
    int dp(int remain, vector<int>& memo){
        // Base case
        if (remain < 2) return remain;
        if (memo[remain] != -1) return memo[remain];
        
        return memo[remain] = dp(remain - 1, memo) + dp(remain - 2, memo);
    }
    
public:
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return dp(n, memo);
    }
};