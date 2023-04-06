class Solution {
    int rows, cols;
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool bfs(int y, int x, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        queue<pair<int, int>> *q = new queue<pair<int, int>>;
        visited[y][x] = true;
        bool isClosed = true;
        q -> push({y, x});
        while (!q -> empty()){
            int y = q -> front().first, x = q -> front().second;
            q -> pop();
            for (auto& [dy, dx] : directions){
                int new_row = y + dy, new_col = x + dx;
                if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols) isClosed = false;
                else if (!grid[new_row][new_col] && !visited[new_row][new_col]){
                    q -> push({new_row, new_col});
                    visited[new_row][new_col] = true;
                }
            }
        }
        
        return isClosed;
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int ans = 0;
        
        for (int y = 0; y < rows; ++y){
            for (int x = 0; x < cols; ++x){
                if (!grid[y][x] && !visited[y][x] && bfs(y, x, visited, grid)) ++ans;
            }
        }
        
        return ans;
    }
};