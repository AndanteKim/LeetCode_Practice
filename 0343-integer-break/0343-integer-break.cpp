class Solution {
private:
    int dp(int num, vector<int>& memo){
        if (num <= 3)
            return num;
        if (memo[num] != 0)
            return memo[num];
        
        int ans = num;
        for (int i = 2; i < num; ++i)
            ans = max(ans, i * dp(num - i, memo));
        return memo[num] = ans;
    }
    
public:
    int integerBreak(int n) {
        vector<int> memo(n + 1);
        
        if (n <= 3)
            return n - 1;
        return dp(n, memo);
    }
};