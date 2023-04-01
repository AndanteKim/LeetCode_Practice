class Solution {
    vector<vector<int>> grid;
    int m, n;
    bool valid(int x, int y, vector<vector<bool>>& visited){
        return x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && this -> grid[x][y] == 1;
    }
    
    int dfs(int x, int y, vector<vector<bool>>& visited){
        if (!valid(x, y, visited)) return 0;
        visited[x][y] = true;
        return 1 + dfs(x + 1, y, visited) + dfs(x - 1, y, visited) + dfs(x, y + 1, visited)\
            + dfs(x, y - 1, visited);
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        this -> grid = grid;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                ans = max(ans, dfs(i, j, visited));
            }
        }
        return ans;
    }
};