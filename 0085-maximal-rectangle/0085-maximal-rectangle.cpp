class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0, m = matrix.size(), n = matrix[0].size();
        vector dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (matrix[i][j] == '0') continue;
                
                // Compute the maximum width and update dp with it
                dp[i][j] = (j > 0)? dp[i][j - 1] + 1:1;
                int width = dp[i][j];
                
                // Compute the maximum area rectangle with a lower right corner at [i, j]
                for (int k = i; k >= 0; --k){
                    width = min(width, dp[k][j]);
                    maxArea = max(maxArea, width * (i - k + 1));
                }
            }
        }
        
        return maxArea;
    }
};