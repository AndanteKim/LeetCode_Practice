class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dists(m, vector<int>(n, std::numeric_limits<int>::max()));
        dists[0][0] = grid[0][0];
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        vector<pair<int, int>> dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop_front();

            if (x == m - 1 && y == n - 1) return true;

            for (auto& [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                int cost = dists[x][y] + grid[nx][ny];
                if (cost >= health) continue;

                if (cost < dists[nx][ny]) {
                    dists[nx][ny] = cost;
                    if (grid[nx][ny] == 0) q.push_front({nx, ny});
                    else q.push_back({nx, ny});
                }
            }
        }
        
        return false;
    }
};