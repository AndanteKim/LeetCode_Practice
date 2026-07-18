class Solution {
private:
    int n;

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        this -> n = grid.size();
        queue<pair<int, int>> multiSrcQueue;

        // Mark thieves as 0 and empty cells as -1, and push thieves to the queue
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    // Push thief coordinates to the queue
                    multiSrcQueue.push({i, j});
                    
                    // Mark thief cell with 0
                    grid[i][j] = 0;
                }
                // Mark empty cell with -1
                else grid[i][j] = -1;
            }
        }

        // Calculate safeness factor for each cell using BFS
        while (!multiSrcQueue.empty()) {
            int sz = multiSrcQueue.size();
            while (sz-- > 0) {
                auto [x, y] = multiSrcQueue.front(); multiSrcQueue.pop();
                int val = grid[x][y];

                for (const auto& [nX, nY] : vector<pair<int, int>>{{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}}) {
                    // Check if the cell is valid and unvisited
                    if (isValid(grid, nX, nY) && grid[nX][nY] == -1) {
                        // Update safeness factor and push to the queue
                        grid[nX][nY] = val + 1;
                        multiSrcQueue.push({nX, nY});
                    }
                }
            }
        }

        int start = 0, end = 0, ans = -1;

        // Binary search for maximum safeness factor
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) 
                // Set end as the maximum safeness factor possible
                end = max(end, grid[i][j]);
        }

        while (start <= end) {
            int mid = start + ((end - start) >> 1);

            if (isValidSafeness(grid, mid)) {
                // Store valid safeness and search for larger ones
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }

        return ans;
    }

    // Check if a given cell lies within the grid
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }

    bool isValidSafeness(vector<vector<int>>& grid, int minSafeness) {
        // Base case: Check if the source and destination cells satisfy minimum safeness
        if (grid[0][0] < minSafeness || grid[n - 1][n - 1] < minSafeness) return false;

        vector visited(n, vector<bool>(n, false));
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        visited[0][0] = true;

        // Breath-first search to find a valid path
        while (!queue.empty()) {
            auto [x, y] = queue.front(); queue.pop();

            if (x == n - 1 && y == n - 1) return true;  // Valid path found

            // Check if the neighboring cell is valid and unvisited
            for (const auto& [nX, nY] : vector<pair<int, int>> {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}}) {
                if (isValid(grid, nX, nY) && !visited[nX][nY] && grid[nX][nY] >= minSafeness) {
                    visited[nX][nY] = true;
                    queue.push({nX, nY});
                }
            }
        }

        return false;   // No valid path found
    }
};