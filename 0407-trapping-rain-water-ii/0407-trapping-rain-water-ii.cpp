class Solution {
private:
    int m, n;
    // Direction arrays
    int dRow[4] = {0, 0, -1, 1}, dCol[4] = {-1, 1, 0, 0};
    
    // Struct to store the height and coordinates of a cell in the grid
    struct Cell{
        int height, row, col;
        
        // Constructor to initialize a cell
        Cell(int height, int row, int col): height(height), row(row), col(col){}
        
        // Overload the comparison operator to make the priority queue a
        // min-heap based on height
        bool operator<(const Cell& others) const{
            // Reverse comparison to simulate a min-heap
            return height >= others.height;
        }
    };

    // Helper function to check if a cell is valid (within grid bounds)
    bool isValid(int row, int col){
        return 0 <= row && row < m && 0 <= col && col < n;
    }

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        this -> m = heightMap.size(), this -> n = heightMap[0].size();
        vector visited(m, vector<bool>(n, false));

        // Priority queue (min-heap) to process boundary cells in increasing height order
        priority_queue<Cell> boundary;

        // Add the first and last column cells to the boundary and mark them as visited
        for (int i = 0; i < m; ++i){
            boundary.push(Cell(heightMap[i][0], i, 0));
            boundary.push(Cell(heightMap[i][n - 1], i, n - 1));

            // Mark left and right boundary cells as visited
            visited[i][0] = visited[i][n - 1] = true;
        }
        
        // Add the first and last row cells to the boundary and mark them as visited
        for (int i = 0; i < n; ++i){
            boundary.push(Cell(heightMap[0][i], 0, i));
            boundary.push(Cell(heightMap[m - 1][i], m - 1, i));
            // Mark top and bottom boundary cells as visited.
            visited[0][i] = visited[m - 1][i] = true;
        }

        int totalWaterVolume = 0;

        while(!boundary.empty()){
            // Pop the cell with the smallest height from the boundary
            auto cell = boundary.top(); boundary.pop();
            int currRow = cell.row, currCol = cell.col, minBoundaryHeight = cell.height;
            
            // Explore all 4 neighboring cells
            for (int d = 0; d < 4; ++d){
                int nextRow = currRow + dRow[d], nextCol = currCol + dCol[d];

                // Check if the neighbor is within the grid bounds and not yet visited
                if (isValid(nextRow, nextCol) && !visited[nextRow][nextCol]){
                    int nextHeight = heightMap[nextRow][nextCol];
                    
                    // If the neighbor's height is less than the current boundary height, water can be trapped. 
                    if (nextHeight < minBoundaryHeight)
                        totalWaterVolume += minBoundaryHeight - nextHeight;
                    
                    // Push the neighbor into the boundary with updated height (to prevent water leakage)
                    boundary.push(Cell(max(nextHeight, minBoundaryHeight), nextRow, nextCol));
                    visited[nextRow][nextCol] = true;
                }
            }
        }

        // Return the total amount of trapped water
        return totalWaterVolume;
    }
};