class Solution {
    int rows, cols;
    int bfs(vector<vector<int>>& grid, int row, int col, int totalHouses){
        int distSum = 0, housesReached = 0;
        queue<pair<int, int>> *q = new queue<pair<int, int>>;
        q -> push({row, col});
        
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        visited[row][col] = true;
        int steps = 0;
        
        while (!q -> empty() && housesReached != totalHouses){
            for (int i = q -> size(); i > 0; --i){
                auto curr = q -> front();
                q -> pop();
                row = curr.first;
                col = curr.second;
                if (grid[row][col] == 1){
                    distSum += steps;
                    ++housesReached;
                    continue;
                }
                
                for (auto& [NextRow, NextCol] : {make_pair(row - 1, col), make_pair(row + 1, col), make_pair(row, col - 1)\
                    , make_pair(row, col + 1)}){
                    if (NextRow >= 0 && NextCol >= 0 && NextRow < rows && NextCol < cols){
                        if (!visited[NextRow][NextCol] && grid[NextRow][NextCol] != 2){
                            visited[NextRow][NextCol] = true;
                            q -> push({NextRow, NextCol});
                        }
                    }
                }
            }
            ++steps;
        }
        
        if (housesReached != totalHouses){
            for (row = 0; row < rows; ++row){
                for (col = 0; col < cols; ++col){
                    if (grid[row][col] == 0 && visited[row][col])
                        grid[row][col] = 2;
                }
            }
            return INT_MAX;
        }
        
        return distSum;
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        int minDist = INT_MAX, totalHouses = 0;
        
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                if (grid[row][col] == 1) ++totalHouses;
            }
        }
        
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                if (grid[row][col] == 0) minDist = min(minDist, bfs(grid, row, col, totalHouses));
            }
        }
        
        if (minDist == INT_MAX) return -1;
        return minDist;
    }
};