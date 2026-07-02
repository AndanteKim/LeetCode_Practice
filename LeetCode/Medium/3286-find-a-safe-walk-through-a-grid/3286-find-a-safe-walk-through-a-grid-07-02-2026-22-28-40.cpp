class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        
        minHeap.push({grid[0][0], 0, 0});

        while (!minHeap.empty()) {
            auto [val, x, y] = minHeap.top(); minHeap.pop();

            if (dist[x][y] >= 0) continue;
            
            dist[x][y] = val;
            for (const auto& [nX, nY] : vector<pair<int, int>>{{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}}) {
                if (0 <= nX && nX < m && 0 <= nY && nY < n && dist[nX][nY] == -1) {
                    minHeap.push({val + grid[nX][nY], nX, nY});
                }
            }
        }

        return dist.back().back() < health;
    }
};