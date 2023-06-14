class Solution {
private:
    int m, n;
    bool valid(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int threshold){
        return 0 <= x && x < m && 0 <= y && y < n && grid[x][y] <= threshold && !visited[x][y];
    }
    
    bool feasible(vector<vector<int>>& grid, int threshold){
        if (grid[0][0] > threshold) return false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        
        while (!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            
            for (auto& [dx, dy] : directions){
                int new_x = x + dx, new_y = y + dy;
                if (valid(new_x, new_y, grid, visited, threshold)){
                    queue.push({new_x, new_y});
                    visited[new_x][new_y] = true;
                }
            }
        }
        return visited[0][0] && visited[m - 1][n - 1];
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int left = 0, right = INT_MIN;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j) right = max(right, grid[i][j]);
        }
        
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (feasible(grid, mid)) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};