class Solution {
    int m, n;
    bool valid(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        return (x >= 0 && x < m) && (y >= 0 && y < n) && !visited[x][y] && grid[x][y];
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        stack<pair<int, int>> *st = new stack<pair<int, int>>;
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n));
        int ans = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (!visited[i][j] && grid[i][j]){
                    int curr = 0;
                    visited[i][j] = true;
                    st -> push({i, j});
                    while (!st -> empty()){
                        auto [x, y] = st -> top();
                        st -> pop();
                        ++curr;
                        for (auto& [dx, dy] : directions){
                            if (valid(x + dx, y + dy, grid, visited)){
                                st -> push({x + dx, y + dy});
                                visited[x + dx][y + dy] = true;
                            }
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};