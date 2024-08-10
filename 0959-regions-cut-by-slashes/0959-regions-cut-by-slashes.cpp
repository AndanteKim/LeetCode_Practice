class Solution {
private:
    // Calculate the index of a triangle in the flattened array
    // Each cell is divided into 4 triangles, numbered 0 to 3 clockwise from the top
    int getTriangleIndex(int gridSize, int row, int col, int triangleNum){
        return (gridSize * row + col) * 4 + triangleNum;
    }
    
    // Union two triangles and return 1 if they were not already connected, 0 otherwise
    int unionTriangles(vector<int>& parentArr, int x, int y){
        int parentX = findParents(parentArr, x), parentY = findParents(parentArr, y);
        
        if (parentX != parentY){
            parentArr[parentX] = parentY;
            return 1;   // Regions were merged, so count decreases by 1
        }
        return 0;   // Regions were already connected
    }
    
    // Find the parent (root) of a set
    int findParents(vector<int>& parentArr, int x){
        if (parentArr[x] == -1)
            return x;
        
        parentArr[x] = findParents(parentArr, parentArr[x]);
        return parentArr[x];
    }
    
    
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size();
        
        // Initially, each small triangle is a separate region
        int totalTriangle = gridSize * gridSize * 4, ans = totalTriangle;
        vector<int> parentArr(totalTriangle, -1);
        
        for (int row = 0; row < gridSize; ++row){
            for (int col = 0; col < gridSize; ++col){
                // Connect with the cell above
                if (row > 0){
                    ans -= unionTriangles(parentArr, getTriangleIndex(gridSize, row - 1, col, 2),\
                                         getTriangleIndex(gridSize, row, col, 0));
                }
                
                // Connect with the cell to the left
                if (col > 0){
                    ans -= unionTriangles(parentArr, getTriangleIndex(gridSize, row, col - 1, 1), \
                                         getTriangleIndex(gridSize, row, col, 3));
                }
                
                // If not '/', connect triangles 0-1 and 2-3
                if (grid[row][col] != '/'){
                    ans -= unionTriangles(parentArr, getTriangleIndex(gridSize, row, col, 0),\
                                         getTriangleIndex(gridSize, row, col, 1));
                    ans -= unionTriangles(parentArr, getTriangleIndex(gridSize, row, col, 2),\
                                         getTriangleIndex(gridSize, row, col, 3));
                }
                
                // If not '\' connect triangles 0-3 and 1-2 
                if (grid[row][col] != '\\'){
                    ans -= unionTriangles(parentArr, getTriangleIndex(gridSize, row, col, 0),\
                                         getTriangleIndex(gridSize, row, col, 3));
                    ans -= unionTriangles(parentArr, getTriangleIndex(gridSize, row, col, 2),\
                                         getTriangleIndex(gridSize, row, col, 1));
                }
            }
        }
        
        return ans;
    }
};