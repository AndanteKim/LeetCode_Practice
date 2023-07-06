class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        
        for (int row = 0; row < m; ++row){
            vector<int> nextRow(n, 0);
            for (int col = 0; col < n; ++col){
                nextRow[col] = dp[col];
                if (col > 0) nextRow[col] = min(nextRow[col - 1], nextRow[col]);
                nextRow[col] += grid[row][col];
            }
            dp = nextRow;
        }
        
        return dp[n - 1];
    }
};