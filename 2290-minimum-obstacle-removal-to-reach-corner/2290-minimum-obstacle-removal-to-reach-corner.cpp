class Solution {
private:
    // Directions for movement: right, left, down, up
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    
    // Helper method to check if the cell is within the grid bounds
    bool isValid(int row, int col){
        return 0 <= row && row < m && 0 <= col && col < n;
    }
    
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();
        
        
        deque<tuple<int, int, int>> dequeCells;
        dequeCells.push_back({0, 0, 0});    // {Obstacles, row, col}
        
        // Distance matrix to store the minimum obstacles removed to reach each cell
        vector minObstacles(m, vector<int>(n, std::numeric_limits<int>::max()));
        
        while (!dequeCells.empty()){
            auto [obstacles, x, y] = dequeCells.front(); dequeCells.pop_front();
            
            // Explore all four possible directions from the current cell
            for (auto& [dx, dy] : directions){
                int newX = x + dx, newY = y + dy;
                if (isValid(newX, newY) && minObstacles[newX][newY] == std::numeric_limits<int>::max()){
                    if (grid[newX][newY]){
                        // If it's an obstacle, add 1 to obstacles and push to the back
                        minObstacles[newX][newY] = obstacles + 1;
                        dequeCells.push_back({minObstacles[newX][newY], newX, newY});
                    }
                    else{
                        // If it's an empty cell, keep the obstacle count and push to the front
                        minObstacles[newX][newY] = obstacles;
                        dequeCells.push_front({minObstacles[newX][newY], newX, newY});
                    }
                }
            }
        }
        
        return minObstacles[m - 1][n - 1];
    }
};