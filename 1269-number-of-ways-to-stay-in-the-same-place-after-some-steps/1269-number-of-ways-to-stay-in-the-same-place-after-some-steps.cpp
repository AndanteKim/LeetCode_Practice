class Solution {
private:
    int mod = 1'000'000'007, arrLen;
    int dp(int curr, int remain, vector<vector<int>>& memo){
        if (remain == 0){
            if (curr == 0)
                return 1;
            return 0;
        }
        
        if (memo[curr][remain] != -1) return memo[curr][remain];
        
        int ans = dp(curr, remain - 1, memo);
        if (curr > 0)
            ans = (ans + dp(curr - 1, remain - 1, memo)) % mod;
        if (curr < arrLen - 1)
            ans = (ans + dp(curr + 1, remain - 1, memo)) % mod;
        
        return memo[curr][remain] = ans;
    }
    
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        this -> arrLen = arrLen;
        vector memo(arrLen, vector<int>(steps + 1, -1));
        return dp(0, steps, memo);
    }
};