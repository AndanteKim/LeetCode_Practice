class Solution {
private:
    int n;

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        this -> n = grid.size();
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

        while (!multiSrcQueue.empty()) {
            int sz = multiSrcQueue.size();
            while (sz-- > 0) {
                auto [x, y] = multiSrcQueue.front(); multiSrcQueue.pop();
                int val = grid[x][y];

                for (const auto& [nX, nY] : vector<pair<int, int>>{{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}}) {
                    if (isValid(grid, nX, nY) && grid[nX][nY] == -1) {
                        grid[nX][nY] = val + 1;
                        multiSrcQueue.push({nX, nY});
                    }
                }
            }
        }

        int start = 0, end = 0, ans = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) end = max(end, grid[i][j]);
        }

        while (start <= end) {
            int mid = start + ((end - start) >> 1);

            if (isValidSafeness(grid, mid)) {
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }

        return ans;
    }

    bool isValid(vector<vector<int>>& grid, int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }

    bool isValidSafeness(vector<vector<int>>& grid, int minSafeness) {
        // Base case
        if (grid[0][0] < minSafeness || grid[n - 1][n - 1] < minSafeness) return false;

        vector visited(n, vector<bool>(n, false));
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        visited[0][0] = true;

        while (!queue.empty()) {
            auto [x, y] = queue.front(); queue.pop();

            if (x == n - 1 && y == n - 1) return true;

            for (const auto& [nX, nY] : vector<pair<int, int>> {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}}) {
                if (isValid(grid, nX, nY) && !visited[nX][nY] && grid[nX][nY] >= minSafeness) {
                    visited[nX][nY] = true;
                    queue.push({nX, nY});
                }
            }
        }

        return false;
    }
};