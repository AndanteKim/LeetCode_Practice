class Solution {
private:
    int n;
    vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // Check if a cell is within bounds and unvisited
    bool notValid(vector<vector<int>>& expandedGrid, int row, int col){
        return row < 0 || row >= n || col < 0 || col >= n || expandedGrid[row][col];
    }
    
    // Flood fill algorithm to mark all cells in a region
    void floodFill(vector<vector<int>>& expandedGrid, int row, int col){
        if (notValid(expandedGrid, row, col))
            return;
        
        expandedGrid[row][col] = 1;
        
        // Check all 4 directions from the current cell
        for (auto& [dr, dc] : directions){
            int newR = row + dr, newC = col + dc;
            floodFill(expandedGrid, newR, newC);
        }
    }
    
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size();
        
        // Create a 3x3 matrix for each cell in the original grid
        vector expandedGrid(gridSize * 3, vector<int>(gridSize * 3));
        
        // Populate the expanded grid based on the original grid
        // 1 represents a barrier in the expanded grid
        for (int i = 0; i < gridSize; ++i){
            for (int j = 0; j < gridSize; ++j){
                int baseRow = i * 3, baseCol = j * 3;
                
                // Check the character in the original grid
                if (grid[i][j] == '\\'){
                    // Mark diagonal for backslash
                    expandedGrid[baseRow][baseCol] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol + 2] = 1;
                }
                else if (grid[i][j] == '/'){
                    // Mark diagonal for forward slash
                    expandedGrid[baseRow + 2][baseCol] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow][baseCol + 2] = 1;
                }
            }
        }
        
        int ans = 0;
        this -> n = expandedGrid.size();
        
        // Count regions using flood fill
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                // If we find an unvisited cell (0), it's a new region
                if (expandedGrid[i][j] == 0){
                    // Fill that region
                    floodFill(expandedGrid, i, j);
                    ++ans;
                }    
            }
        }
        
        return ans;
    }
};