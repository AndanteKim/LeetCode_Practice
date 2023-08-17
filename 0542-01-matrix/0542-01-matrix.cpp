class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dp;
        for (vector<int>& row : mat) dp.emplace_back(row.begin(), row.end());
        int m = mat.size(), n = mat[0].size();
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                int minNeighbor = m * n;
                if (dp[i][j]){
                    if (i > 0) minNeighbor = min(minNeighbor, dp[i - 1][j]);
                    if (j > 0) minNeighbor = min(minNeighbor, dp[i][j - 1]);
                    dp[i][j] = minNeighbor + 1;
                }
                
            }
        }
        
        for (int r = m - 1; r >= 0; --r){
            for (int c = n - 1; c >= 0; --c){
                int minNeighbor = m * n;
                if (dp[r][c]){
                    if (r < m - 1) minNeighbor = min(minNeighbor, dp[r + 1][c]);
                    if (c < n - 1) minNeighbor = min(minNeighbor, dp[r][c + 1]);
                    dp[r][c] = min(dp[r][c], minNeighbor + 1);
                }
                
            }
        }
        
        return dp;
    }
};