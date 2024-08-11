class Solution {
private:
    int m, n;
    vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool notValid(const int row, const int col, const vector<vector<bool>>& visited, const vector<vector<int>>& grid){
        return row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || grid[row][col] == 0;
    }
    
    int countIslands(const vector<vector<int>>& grid){
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1 && !visited[i][j]){
                    exploreIslands(i, j, visited, grid);
                    ++count;
                }
            }
        }
        
        return count;
    }
    
    void exploreIslands(const int row, const int col, vector<vector<bool>>& visited, const vector<vector<int>>& grid){
        if (notValid(row, col, visited, grid))
            return;
        
        visited[row][col] = true;
        
        for (auto& [dr, dc] : directions){
            int newR = row + dr, newC = col + dc;
            exploreIslands(newR, newC, visited, grid);
        }
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();
        
        // Base case: Check if already disconnected
        if (countIslands(grid) != 1)
            return 0;
        
        // Check if can be disconnected in one day.
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j]){
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        // If can't be disconnected in 0 or 1 day, return 2
        return 2;
    }
};