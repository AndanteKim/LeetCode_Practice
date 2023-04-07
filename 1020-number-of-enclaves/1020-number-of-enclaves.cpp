class Solution {
    int m, n;
    void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        
        while (!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (auto& [new_row, new_col] : {make_pair(x - 1, y), make_pair(x + 1, y), make_pair(x, y - 1), make_pair(x, y + 1)}){
                if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n) continue;
                else if (grid[new_row][new_col] && !visited[new_row][new_col]){
                    q.push({new_row, new_col});
                    visited[new_row][new_col] = true;
                }
            }
        }
        return;
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        for (int i = 0; i < m; ++i){
            if (grid[i][0] && !visited[i][0]) bfs(i, 0, grid, visited);
            if (grid[i][n - 1] && !visited[i][n - 1]) bfs(i, n - 1, grid, visited);
        }
        
        for (int i = 0; i < n; ++i){
            if (grid[0][i] && !visited[0][i]) bfs(0, i, grid, visited);
            if (grid[m - 1][i] && !visited[m - 1][i]) bfs(m - 1, i, grid, visited);
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