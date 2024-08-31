class Solution {
private:
    int rows, cols;
    
    // Directions in which we can traverse inside the grids.
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    bool isCellLand(int x, int y, vector<vector<int>>& grid){
        return grid[x][y] == 1;
    }
    
    // Traverse all cells of island starting at position (x, y) in 'grid2',
    // and check this island is a sub-island in 'grid1'.
    bool isSubIsland(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited){
        bool isSubIsland = true;
        
        visited[x][y] = true;
        
        // Push the starting cell in the queue and mark it as visited.
        queue<pair<int, int>> queue;
        queue.push({x, y});
       
        // Traverse on all cells using the breadthh-first search method.
        while (!queue.empty()){
            auto [currX, currY] = queue.front(); queue.pop();
            
            // If the current position cell isn't a land cell in 'grid1',
            // then the current island can't be a sub-island.
            if (!isCellLand(currX, currY, grid1))
                isSubIsland &= false;
            
            for (const auto& [dx, dy] : directions){
                int nextX = currX + dx, nextY = currY + dy;
                
                // If the next cell is inside 'grid2', is never visited, and
                // is a land cell, then we traverse to the next cell.
                if (0 <= nextX && nextX < rows && 0 <= nextY && nextY < cols && \
                    !visited[nextX][nextY] && isCellLand(nextX, nextY, grid2)){
                    
                    // Push the next cell in the queue and mark it as visited.
                    visited[nextX][nextY] = true;
                    queue.push({nextX, nextY});
                }
            }
        }
        
        return isSubIsland;
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        this -> rows = grid2.size(), this -> cols = grid2[0].size();
        int countOfSubIslands = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Iterate on each cell in 'grid2'
        for (int x = 0; x < rows; ++x){
            for (int y = 0; y < cols; ++y){
                // If cell at the position (x, y) in the 'grid2' isn't visited,
                // is a land cell in 'grid2', and the island
                // starting from this cell is a sub-island in 'grid1', then we
                // increment the count of sub-islands.
                if (!visited[x][y] && isCellLand(x, y, grid2) && \
                    isSubIsland(x, y, grid1, grid2, visited))
                    ++countOfSubIslands;
            }
        }
        
        // Return total count of sub-islands
        return countOfSubIslands;
    }
};