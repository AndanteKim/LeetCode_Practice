class Solution {
    int m, n;
    bool isNext(int x, int y, vector<vector<int>>& grid){
        if ((x >= 0 && x < m) && (y >= 0 && y < n) && grid[x][y] == 1) return true;
        return false;
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>> queue;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if (grid[i][j] == 1) queue.push({i, j});
            }
        }
        int ans = 4 * queue.size();
        while (!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            for (auto& [dx, dy] : directions){
                if (isNext(x + dx, y + dy, grid))
                    --ans;
            }
            
        }
        
        return ans;
    }
};