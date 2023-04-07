class Solution {
    int rows, cols;
    
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if (x < 0 || x >= rows || y < 0 || y >= cols || !grid[x][y] || visited[x][y]) return;
        
        visited[x][y] = true;
        for (auto& [new_row, new_col] : {make_pair(x - 1, y), make_pair(x + 1, y), make_pair(x, y - 1), make_pair(x, y + 1)}){
            dfs(new_row, new_col, grid, visited);
        }
        return;
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        
        for (int i = 0; i < rows; ++i){
            if (grid[i][0] == 1 && !visited[i][0]) dfs(i, 0, grid, visited);
            if (grid[i][cols - 1] == 1 && !visited[i][cols - 1]) dfs(i, cols - 1, grid, visited);
        }
        
        for (int i = 0; i < cols; ++i){
            if (grid[0][i] == 1 && !visited[0][i]) dfs(0, i, grid, visited);
            if (grid[rows - 1][i] == 1 && !visited[rows - 1][i]) dfs(rows - 1, i, grid, visited);
        }
        
        int ans = 0;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j] && !visited[i][j]) ++ans;
            }
        }
        return ans;
    }
};