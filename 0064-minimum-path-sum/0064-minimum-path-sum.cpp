class Solution {
private:
    int dp(int row, int col, vector<vector<int>>& memo, vector<vector<int>>& grid){
        if (row + col == 0) return grid[0][0];
        if (memo[row][col] != -1) return memo[row][col];
        int ans = INT_MAX;
        if (row > 0) ans = min(ans, dp(row - 1, col, memo, grid));
        if (col > 0) ans = min(ans, dp(row, col - 1, memo, grid));
        
        return memo[row][col] = ans + grid[row][col];
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dp(m - 1, n - 1, memo, grid);
    }
};