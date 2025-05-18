class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0, rowHits = 0;
        vector<int> colHits(n, 0);

        for (int row = 0; row < m; ++row){
            for (int col = 0; col < n; ++col){
                // Reset the hits on the row, if necessary.
                if (col == 0 || grid[row][col - 1] == 'W'){
                    rowHits = 0;
                    for (int k = col; k < n; ++k){
                        // Stop the scan when we hit the wall.
                        if (grid[row][k] == 'W') break;
                        if (grid[row][k] == 'E') ++rowHits;
                    }
                }

                // Reset the hits on the col, if necessary.
                if (row == 0 || grid[row - 1][col] == 'W'){
                    colHits[col] = 0;
                    for (int k = row; k < m; ++k){
                        if (grid[k][col] == 'W') break;
                        if (grid[k][col] == 'E') ++colHits[col];
                    }
                }

                // Count the hits for each empty cell.
                if (grid[row][col] == '0'){
                    int totalHits = rowHits + colHits[col];
                    ans = max(ans, totalHits);
                }
            }
        }

        return ans;
    }
};