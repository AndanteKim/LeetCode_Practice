class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j)
                if (matrix[i][j]){
                    // min(right, min(diagonal, below)) + 1
                    dp[i + 1][j + 1] = min(dp[i][j + 1], min(dp[i][j], dp[i + 1][j])) + 1;
                    ans += dp[i + 1][j + 1];
                }
        }
        
        return ans;
    }
};