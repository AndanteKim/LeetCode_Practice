class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i) dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int i = 1; i < m; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int row = 1; row < m; ++row){
            for (int col = 1; col < n; ++col){
                dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};