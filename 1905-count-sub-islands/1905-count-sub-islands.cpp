class Solution {
private:
    int rows, cols;
    
    // Directions in which we can traverse inside the grids.
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    bool isCellLand(int x, int y, vector<vector<int>>& grid){
        return grid[x][y] == 1;
    }
    
    // Traverse all cells of island starting at position (x, y) in 'grid2',
    // and check if this island is a sub-island of 'grid1'.
    bool isSubIsland(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited){
        // Traverse on all cells using the depth-first search method.
        bool isIsland = true;
        
        // If the current cell isn't a land cell in 'grid1', then the current island can't be a sub-island.
        if (!isCellLand(x, y, grid1))
            isIsland = false;
        
        // Traverse on all adjacent cells.
        for (auto& [dx, dy] : directions){
            int newX = x + dx, newY = y + dy;
            
            // If the next cell is inside 'grid2', is not visited, and is a land cell,
            // then we traverse to the next cell.
            if (0 <= newX && newX < rows && 0 <= newY && newY < cols && !visited[newX][newY] && isCellLand(newX, newY, grid2)){
                // Mark the next cell as visited.
                visited[newX][newY] = true;
                bool nextPartOfIsland = isSubIsland(newX, newY, grid1, grid2, visited);
                isIsland &= nextPartOfIsland;
            }
        }
        
        return isIsland;
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        this -> rows = grid2.size(), this -> cols = grid2[0].size();
        
        int subIslandCount = 0;
        
        // Iterate over each cell in 'grid2'.
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int x = 0; x < rows; ++x){
            for (int y = 0; y < cols; ++y){
                // If the cell at the position (x, y) in 'grid2' isn't visited,
                // is a land cell in 'grid2', and the island starting from this cell is a 
                // sub-island in 'grid1', then increment the count of sub-islands.
                if (!visited[x][y] && isCellLand(x, y, grid2)){
                    visited[x][y] = true;
                    if (isSubIsland(x, y, grid1, grid2, visited))
                        ++subIslandCount;
                }
            }
        }
        
        // Return total count of sub-islands.
        return subIslandCount;
    }
};