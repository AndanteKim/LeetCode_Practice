class Solution {
    int n;
private:
    int f(int p, int i, int m, vector<int>& piles, vector<vector<vector<int>>>& dp){
        if (i == n) return 0;
        
        if (dp[p][i][m] != -1) return dp[p][i][m];
        int res = p == 1? 1000000 : -1, s = 0;
        for (int x = 1; x <= min(2 * m, n - i); ++x){
            s += piles[i + x - 1];
            if (p == 0)
                res = max(res, s + f(1, i + x, max(m, x), piles, dp));
            else
                res = min(res, f(0, i + x, max(m, x), piles, dp));
        }
        
        return dp[p][i][m] = res;
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        this -> n = piles.size();
        vector dp(2, vector(n + 1, vector<int>(n + 1, -1)));
        
        return f(0, 0, 1, piles, dp);
    }
};