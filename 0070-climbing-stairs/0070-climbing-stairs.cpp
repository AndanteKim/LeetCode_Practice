class Solution {
private:
    int dfs(int remain, vector<int>& memo){
        if (remain <= 0)
            return remain < 0? 0:1;
        if (memo[remain] != -1)
            return memo[remain];
        
        return memo[remain] = dfs(remain - 1, memo) + dfs(remain - 2, memo);
    }
    
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        
        return dfs(n, memo);
    }
};