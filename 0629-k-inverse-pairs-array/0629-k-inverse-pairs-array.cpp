class Solution {
private:
    int dp(int n, int k, vector<vector<int>>& memo){
        if (n == 0) return 0;
        if (k == 0) return 1;
        
        if (memo[n][k] != -1)
            return memo[n][k];
        
        int inv = 0;
        for (int i = 0; i <= min(k, n - 1); ++i)
            inv = (inv + dp(n - 1, k - i, memo)) % 1'000'000'007;
        return memo[n][k] = inv;
    }
    
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> memo(1001, vector<int>(1001, -1));
        return dp(n, k, memo);
    }
};