class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> multiSrcQueue;

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

        // Check if a given cell lies within the grid
        auto isValid = [&](int i, int j) -> bool {
            return 0 <= i && i < n && 0 <= j && j < n;
        };
        
        // Calculate safeness factor for each cell using BFS
        while (!multiSrcQueue.empty()) {
            int sz = multiSrcQueue.size();
            while (sz-- > 0){
                auto [x, y] = multiSrcQueue.front(); multiSrcQueue.pop();
                int val = grid[x][y];
                // Check neighboring cells
                for (const auto& [nX, nY] : vector<pair<int, int>> {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}}) {
                    // Check if the cell is valid and unvisited
                    if (isValid(nX, nY) && grid[nX][nY] == -1) {
                        // Update safeness factor and push to the queue
                        grid[nX][nY] = val + 1;
                        multiSrcQueue.push({nX, nY});
                    }
                }
            }
        }

        // Priority queue to prioritize cells with hight safeness factor
        // {maximum_safeness_till_now, x-coords, y-coords}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;        // Mark the source cell as visited;

        // BFS to find the path within maximum safeness factor
        while (!pq.empty()) {
            auto [safeness, x, y] = pq.top(); pq.pop();

            // If reached the destination, return safeness factor
            if (x == n - 1 && y == n - 1) return safeness;

            // Check neighboring cells
            for (const auto& [nX, nY] : vector<pair<int, int>> {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}}) {
                // Check if the neighboring cell is valid and unvisited
                if (isValid(nX, nY) && grid[nX][nY] != -1) {
                    pq.push({min(safeness, grid[nX][nY]), nX, nY});
                    grid[nX][nY] = -1;
                }
            }

        }

        return -1;
    }
};