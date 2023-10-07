typedef long long ll;

class Solution {
private:
    int MOD = 1'000'000'007;
    int n, m;
    int dp(vector<vector<vector<int>>> &memo, int i, int maxSoFar, int remain){
        if (i == n){
            if (remain == 0)
                return 1;
            return 0;
        }
        
        if (remain < 0) return 0;
        
        if (memo[i][maxSoFar][remain] != -1)
            return memo[i][maxSoFar][remain];
        
        int ans = 0;
        
        for (int num = 1; num <= maxSoFar; ++num)
            ans = (ans + dp(memo, i + 1, maxSoFar, remain)) % MOD;
        for (int num = maxSoFar + 1; num <= m; ++num){
            ans = (ans + dp(memo, i + 1, num, remain - 1)) % MOD;
        }
        return memo[i][maxSoFar][remain] = ans;
    }
    
public:
    int numOfArrays(int n, int m, int k) {
        this -> n = n, this -> m = m;
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        
        return dp(memo, 0, 0, k);
    }
};