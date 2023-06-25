class Solution {
private:
    int m, n;
    
    int backtrack(int row, int col, int remain, vector<vector<int>>& grid){
        if (grid[row][col] == 2){
            return remain == 1? 1: 0;
        }
        
        int temp = grid[row][col];
        grid[row][col] = -4;
        --remain;
        int ans = 0;
        
        for (auto& [r, c] : vector<pair<int, int>>{{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}}){
            if (r < 0 || c < 0 || r >= m || c >= n) continue;
            if (grid[r][c] < 0) continue;
            ans += backtrack(r, c, remain, grid);
        }
        grid[row][col] = temp;
        return ans;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int nonObstacles = 0, startRow, startCol;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] >= 0) ++nonObstacles;
                if (grid[i][j] == 1){
                    startRow = i, startCol = j;
                }
            }
        }
        
        return backtrack(startRow, startCol, nonObstacles, grid);
    }
};