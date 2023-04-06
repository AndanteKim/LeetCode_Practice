class Solution {
    int rows, cols;
    vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    bool dfs(int y, int x, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        if (y < 0 || y >= rows || x < 0 || x >= cols) return false;
        if (grid[y][x] || visited[y][x]) return true;
        visited[y][x] = true;
        bool isClosed = true;
        for (auto& [dy, dx] : directions){
            int new_rows = y + dy, new_cols = x + dx;
            if (!dfs(new_rows, new_cols, visited, grid)) isClosed = false;
        }
        
        return isClosed;
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int ans = 0;
        
        for (int y = 0; y < rows; ++y){
            for (int x = 0; x < cols; ++x){
                if (grid[y][x] == 0 && !visited[y][x] && dfs(y, x, visited, grid)) ++ans;
            }
        }
        
        return ans;
    }
};