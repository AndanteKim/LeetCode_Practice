class Solution {
private:
    int n;
    
    // Check if a cell is within bounds and unvisited
    bool isValid(vector<vector<int>>& expandedGrid, int row, int col){
        return 0 <= row && row < n && 0 <= col && col < n && expandedGrid[row][col] == 0;
    }
    
    // Flood fill algorithm to mark all cells in a region
    void floodFill(vector<vector<int>>& expandedGrid, int row, int col){
        expandedGrid[row][col] = 1;
        queue<pair<int, int>> queue;
        queue.push({row, col});
            
        while (!queue.empty()){
            auto [r, c] = queue.front(); queue.pop();
            
            // Check all four directions from the current cell
            for (auto& [dr, dc] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}){
                int newR = r + dr, newC = c + dc;
                
                // If the new cell is valid and unvisited, mark it and add to queue
                if (isValid(expandedGrid, newR, newC)){
                    expandedGrid[newR][newC] = 1;
                    queue.push({newR, newC});
                }
            }
        }
        
    }
    
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size(), ans = 0;
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
        
        // Flood fill algorithm
        this -> n = expandedGrid.size();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (expandedGrid[i][j] == 0){
                    floodFill(expandedGrid, i, j);
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};