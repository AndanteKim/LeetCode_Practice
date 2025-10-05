class Solution {
private:
    vector<vector<bool>> bfs(const vector<vector<int>>& heights, queue<pair<int, int>> &q){
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> reachable(m, vector<bool>(n, false));
        
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // This cell is reachable, so mark it.
            if (reachable[row][col]) {
                continue;
            }
            reachable[row][col] = true;

            // Check all 4 directions
            for (const auto& dir : directions) {
                int new_r = row + dir.first;
                int new_c = col + dir.second;
                
                // Check if the new cell is within bounds
                if (new_r < 0 || new_r >= m || new_c < 0 || new_c >= n) {
                    continue;
                }
                
                // Check that the new cell hasn't already been visited
                if (reachable[new_r][new_c]) {
                    continue;
                }
                
                // Check that the new cell has a higher or equal height,
                // so that water can flow from the new cell to the old cell
                if (heights[new_r][new_c] < heights[row][col]) {
                    continue;
                }

                // If we've gotten this far, that means the new cell is reachable
                q.push({new_r, new_c});
            }
        }
        
        return reachable;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Check if input is empty
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int m = heights.size();
        int n = heights[0].size();

        // Setup each queue with cells adjacent to their respective ocean
        queue<pair<int, int>> pacific_queue;
        queue<pair<int, int>> atlantic_queue;

        for (int i = 0; i < m; ++i) {
            pacific_queue.push({i, 0});
            atlantic_queue.push({i, n - 1});
        }
            
        for (int j = 0; j < n; ++j) {
            pacific_queue.push({0, j});
            atlantic_queue.push({m - 1, j});
        }
        
        // Perform a BFS for each ocean to find all cells accessible by each ocean
        auto pacific_reachable = bfs(heights, pacific_queue);
        auto atlantic_reachable = bfs(heights, atlantic_queue);
        
        // Find all cells that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific_reachable[i][j] && atlantic_reachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};