class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    ans += bfs(i, j, grid, visited, k);
                }
            }
        }
        return ans;
    }

private:
    bool bfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int k) {
        int m = grid.size(), n = grid[0].size();
        long long val = grid[x][y];
        queue<pair<int,int>> q;
        q.push({x, y});
        visited[x][y] = true;  // mark visited immediately when pushed

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                    !visited[ni][nj] && grid[ni][nj] != 0) {
                    visited[ni][nj] = true;  // mark before pushing
                    val += grid[ni][nj];
                    q.push({ni, nj});
                }
            }
        }
        return val % k == 0;
    }
};