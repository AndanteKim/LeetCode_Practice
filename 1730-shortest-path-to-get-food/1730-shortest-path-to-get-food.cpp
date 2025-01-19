class Solution {
private:
    int m, n;

    // Check if position is within bounds and not blocked
    bool isValid(vector<vector<char>>& grid, int i, int j){
        return 0 <= i && i < m && 0 <= j && j < n && grid[i][j] != 'X';
    }

public:
    int getFood(vector<vector<char>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();

        // BFS queue for level-by-level traversal
        queue<pair<int, int>> queue;

        // Find starting position markedas '*'
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '*'){
                    queue.push({i, j});
                    break;
                }
        }

        // Possible moves: right, left, up, down
        vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int steps = 1;

        // BFS traversal
        while (!queue.empty()){
            int size = queue.size();

            // Process all cells at current level
            while (size-- > 0){
                auto [r, c] = queue.front(); queue.pop();
                
                // Try all four directions
                for (auto& [dr, dc] : dirs){
                    int nextR = r + dr, nextC = c + dc;

                    if (isValid(grid, nextR, nextC)){
                        // Found food
                        if (grid[nextR][nextC] == '#')
                            return steps;

                        // Mark as visited and add to queue
                        grid[nextR][nextC] = 'X';
                        queue.push({nextR, nextC});
                    }
                }
            }
            ++steps;
        }

        // No path found to food
        return -1;
    }
};