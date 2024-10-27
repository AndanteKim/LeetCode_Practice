class Solution {
private:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        // If the cell lies outside the grid, return 0.
        if (i >= m || j >= n) return 0;
        
        if (!matrix[i][j]) return 0;
        
        // If we've already visited the cell, return the memoized value.
        if (dp[i][j] != -1) return dp[i][j];
        
        // Find the answer for the cell to the right of the current cell.
        int right = solve(i, j + 1, matrix, dp);
        
        // Find the answer for the cell to the diagonal of the current cell.
        int diagonal = solve(i + 1, j + 1, matrix, dp);
        
        // Find the answer for the cell below the current cell. 
        int below = solve(i + 1, j, matrix, dp);
        
        dp[i][j] = 1 + min(right, min(diagonal, below));
        
        return dp[i][j];
    }
    
public:
    int countSquares(vector<vector<int>>& matrix) {
        this -> m = matrix.size(), this -> n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j)
                ans += solve(i, j, matrix, dp);
        }
        
        return ans;
    }
};