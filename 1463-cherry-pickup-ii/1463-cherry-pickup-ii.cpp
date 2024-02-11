class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector dp(m, vector(n, vector<int>(n, 0)));
        
        for (int row = m - 1; row >= 0; --row){
            for (int col1 = 0; col1 < n; ++col1){
                for (int col2 = 0; col2 < n; ++col2){
                    // current cell
                    int ans = grid[row][col1];
                    
                    if (col1 != col2)
                        ans += grid[row][col2];
                    // transition
                    if (row != m - 1){
                        int curr = 0;
                        for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; ++newCol1){
                            for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; ++newCol2){
                                if (newCol1 >= 0 && newCol1 < n && newCol2 >= 0 && newCol2 < n)
                                    curr = max(curr, dp[row + 1][newCol1][newCol2]);
                            }
                        }
                        ans += curr;
                    }
                    dp[row][col1][col2] = ans;
                }
            }
        }
        
        return dp[0][0][n - 1];
    }
};