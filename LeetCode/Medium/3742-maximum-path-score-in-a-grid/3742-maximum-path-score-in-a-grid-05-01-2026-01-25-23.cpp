class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, std::numeric_limits<int>::min())));
        dp[0][0][0] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int c = 0; c <= k; ++c) {
                    if (dp[i][j][c] == std::numeric_limits<int>::min()) continue;
                    
                    if (i + 1 < m) {
                        int cost = grid[i + 1][j] > 0? 1 : 0;
                        
                        if (c + cost <= k)
                            dp[i + 1][j][c + cost] = max(dp[i + 1][j][c + cost], dp[i][j][c] + grid[i + 1][j]);
                    }

                    if (j + 1 < n) {
                        int cost = grid[i][j + 1] > 0? 1 : 0;

                        if (c + cost <= k)
                            dp[i][j + 1][c + cost] = max(dp[i][j + 1][c + cost], dp[i][j][c] + grid[i][j + 1]);
                    }
                }
            }
        }

        int ans = *max_element(dp[m - 1][n - 1].begin(), dp[m - 1][n - 1].end());
        return ans < 0? -1 : ans;
    }
};