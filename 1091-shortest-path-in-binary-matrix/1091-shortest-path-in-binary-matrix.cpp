class Solution {
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1},\
                                      {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    int m, n;
    bool valid(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        return (x >= 0 && x < m) && (y >= 0 && y < n) && !grid[x][y] && !visited[x][y];
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        m = grid.size(), n = grid[0].size();
        queue<vector<int>> *q = new queue<vector<int>>;
        vector<vector<bool>> visited(m, vector<bool>(n));
        q -> push({0, 0, 1});
        
        while (!q -> empty()){
            auto it = q -> front();
            int x = it[0], y = it[1], path = it[2];
            q -> pop();
            if (x == m - 1 && y == n - 1) return path;
            
            for (auto& [dx, dy] : directions){
                if (valid(x + dx, y + dy, grid, visited)){
                    visited[x + dx][y + dy] = true;
                    q -> push({x + dx, y + dy, path + 1});
                }
            }
        }
        
        return -1;
        
    }
};