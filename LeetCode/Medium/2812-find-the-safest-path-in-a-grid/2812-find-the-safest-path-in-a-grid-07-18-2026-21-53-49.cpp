class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> multiSrcQueue;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    multiSrcQueue.push({i, j});
                    grid[i][j] = 0;
                }
                else grid[i][j] = -1;
            }
        }

        auto isValid = [&](int i, int j) -> bool {
            return 0 <= i && i < n && 0 <= j && j < n;
        };

        while (!multiSrcQueue.empty()) {
            int sz = multiSrcQueue.size();
            while (sz-- > 0){
                auto [x, y] = multiSrcQueue.front(); multiSrcQueue.pop();
                int val = grid[x][y];
                for (const auto& [nX, nY] : vector<pair<int, int>> {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}}) {
                    if (isValid(nX, nY) && grid[nX][nY] == -1) {
                        grid[nX][nY] = val + 1;
                        multiSrcQueue.push({nX, nY});
                    }
                }
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;        // Mark the grid as visited;

        while (!pq.empty()) {
            auto [safeness, x, y] = pq.top(); pq.pop();

            if (x == n - 1 && y == n - 1) return safeness;

            for (const auto& [nX, nY] : vector<pair<int, int>> {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}}) {
                if (isValid(nX, nY) && grid[nX][nY] != -1) {
                    pq.push({min(safeness, grid[nX][nY]), nX, nY});
                    grid[nX][nY] = -1;
                }
            }

        }

        return -1;
    }
};