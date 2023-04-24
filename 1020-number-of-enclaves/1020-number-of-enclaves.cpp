class Solution {
    int m, n;
    
    void dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || !grid[x][y]) return;
        visited[x][y] = true;
        vector<pair<int, int>> directions{{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
        for (auto& [new_x, new_y] : directions) dfs(new_x, new_y, visited, grid);
        return;
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            if (grid[i][0] && !visited[i][0]) dfs(i, 0, visited, grid);
            if (grid[i][n - 1] && !visited[i][n - 1]) dfs(i, n - 1, visited, grid);
        }
        
        for (int i = 0; i < n; ++i){
            if (grid[0][i] && !visited[0][i]) dfs(0, i, visited, grid);
            if (grid[m - 1][i] && !visited[m - 1][i]) dfs(m - 1, i, visited, grid);
        }
        int ans = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] && !visited[i][j]) ++ans;
            }
        }
        
        return ans;
    }
};