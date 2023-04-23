class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        
        for (int r = 0; r < rows; ++r){
            for (int c = 0; c < cols; ++c){
                if (grid[r][c] == 1){
                    ans += 4;
                    if (r > 0 && grid[r - 1][c] == 1) ans -= 2;
                    if (c > 0 && grid[r][c - 1] == 1) ans -= 2;
                }
            }
        }
        
        return ans;
    }
};