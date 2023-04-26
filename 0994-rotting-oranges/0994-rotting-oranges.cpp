class Solution {
    bool valid(int x, int y, int rows, int cols, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        if (x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y] || grid[x][y] != 1)
            return false;
        grid[x][y] = 2;
        visited[x][y] = true;
        return true;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, freshOrange = 0, rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> queue;
        
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j] == 2) queue.push({i, j});
                else if (grid[i][j] == 1) ++freshOrange;
            }
        }
        
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        while (!queue.empty()){
            int sz = queue.size();
            for (int i = 0; i < sz; ++i){
                auto [x, y] = queue.front();
                queue.pop();
                
                for (auto [new_x, new_y] : {make_pair(x - 1, y), make_pair(x + 1, y), make_pair(x, y - 1), make_pair(x, y + 1)}){
                    if (valid(new_x, new_y, rows, cols, visited, grid)){
                        queue.push({new_x, new_y});
                        --freshOrange;
                    }
                }
            }
            if (!queue.empty()) ++ans;
        }
        
        return freshOrange == 0? ans : -1;
    }
};