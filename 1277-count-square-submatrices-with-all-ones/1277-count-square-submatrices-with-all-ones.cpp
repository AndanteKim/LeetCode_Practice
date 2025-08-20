class Solution {
private:
    int row, col;
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if (i >= row || j >= col) return 0;
        if (matrix[i][j] == 0) return 0;

        // Memoized
        if (dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, matrix, dp), diagonal = solve(i + 1, j + 1, matrix, dp), below = solve(i + 1, j, matrix, dp);
        dp[i][j] = min(right, min(diagonal, below)) + 1;
        
        return dp[i][j];
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        row = matrix.size(), col = matrix[0].size();
        vector dp(row, vector<int>(col, -1));

        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j)
                ans += solve(i, j, matrix, dp);
        }

        return ans;
    }
};