class Solution {
private:
    int rows, cols;
    
    bool isValid(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        return 0 <= x && x < rows && 0 <= y && y < cols && !visited[x][y] && grid[x][y] == 1;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        this -> rows = grid.size(), this -> cols = grid[0].size();
        int fresh = 0, ans = 0;
        queue<vector<int>> queue;
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j] == 1) ++fresh;
                if (grid[i][j] == 2) queue.push({i, j, 0});
            }
        }
        
        
        while (!queue.empty()){
            auto it = queue.front();
            queue.pop();
            int x = it[0], y = it[1], days = it[2];
            ans = max(ans, days);
            
            for (auto& [newX, newY] : vector<pair<int, int>> {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}){
                if (isValid(newX, newY, grid, visited)){
                    visited[newX][newY] = true;
                    grid[newX][newY] = 2;
                    --fresh;
                    queue.push({newX, newY, days + 1});
                }
            }
        }
        
        return fresh > 0? -1 : ans;
    }
};