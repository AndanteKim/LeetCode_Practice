class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        constexpr int MOD = 1'000'000'007;
        vector dp(m + 1, vector(n + 1, vector<int>(k, 0)));

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (i == 1 && j == 1) {
                    dp[i][j][grid[0][0] % k] = 1;
                    continue;
                }

                int val = grid[i - 1][j - 1] % k;
                for (int r = 0; r < k; ++r) {
                    int prevMod = (r - val + k) % k;
                    dp[i][j][r] = (dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod]) % MOD;
                }
            }
        }
        
        return dp[m][n][0];
    }
};