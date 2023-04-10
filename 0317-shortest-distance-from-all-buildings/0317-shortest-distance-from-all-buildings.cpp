class Solution {
    int rows, cols;
    void bfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& distances, int row, int col){
        queue<pair<int, int>> *q = new queue<pair<int, int>>;
        q -> push({row, col});
        
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        visited[row][col] = true;
        int steps = 0;
        
        while (!q -> empty()){
            for (int i = q -> size(); i > 0; --i){
                auto curr = q -> front();
                q -> pop();
                row = curr.first;
                col = curr.second;
                if (grid[row][col] == 0){
                    distances[row][col][0] += steps;
                    ++distances[row][col][1];
                }
                
                for (auto& [NextRow, NextCol] : {make_pair(row - 1, col), make_pair(row + 1, col), make_pair(row, col - 1)\
                    , make_pair(row, col + 1)}){
                    if (NextRow >= 0 && NextCol >= 0 && NextRow < rows && NextCol < cols){
                        if (!visited[NextRow][NextCol] && grid[NextRow][NextCol] == 0){
                            visited[NextRow][NextCol] = true;
                            q -> push({NextRow, NextCol});
                        }
                    }
                }
            }
            ++steps;
        }
        
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        int minDist = INT_MAX, totalHouses = 0;
        
        vector<vector<vector<int>>> distances (rows, vector<vector<int>> (cols, {0, 0}));
        
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                if (grid[row][col] == 1) {
                    ++totalHouses;
                    bfs(grid, distances, row, col);
                }
            }
        }
        
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                if (distances[row][col][1] == totalHouses) minDist = min(minDist, distances[row][col][0]);
            }
        }
        
        if (minDist == INT_MAX) return -1;
        return minDist;
    }
};