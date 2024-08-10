class Solution {
private:
    int find(vector<int>& parentArr, int x){
        if (parentArr[x] == -1)
            return x;
        
        parentArr[x] = find(parentArr, parentArr[x]);
        return parentArr[x];
    }
    
    int disjoint(vector<int>& parentArr, int node1, int node2){
        int parent1 = find(parentArr, node1), parent2 = find(parentArr, node2);
        
        if (parent1 == parent2)
            return 1;
        
        parentArr[parent1] = parent2;   // Nodes are already in the same set, new region formed.
        return 0;                       // No new region formed.
    }
    
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size(), pointPerSide = gridSize + 1;
        int totalPoints = pointPerSide * pointPerSide;
        
        // Initialize disjoint set data structure.
        vector<int> parentArr(totalPoints, -1);
        
        // Connect the border points.
        for (int i = 0; i < pointPerSide; ++i){
            for (int j = 0; j < pointPerSide; ++j){
                if (i == 0 || j == 0 || i == pointPerSide - 1 || j == pointPerSide - 1)
                    parentArr[i * pointPerSide + j] = 0;
            }
        }
        
        // Set the parent of the top-left corner to itself.
        parentArr[0] = -1;
        
        // Start with one region (the border)
        int ans = 1;
        
        // Process each cell in the grid.
        for (int i = 0; i < gridSize; ++i){
            for (int j = 0; j < gridSize; ++j){
                // Treat each slash as an edge connecting two points
                if (grid[i][j] == '/'){
                    int topRight = i * pointPerSide + j + 1;
                    int bottomLeft = (i + 1) * pointPerSide + j;
                    ans += disjoint(parentArr, topRight, bottomLeft);
                }
                else if (grid[i][j] == '\\'){
                    int topLeft = i * pointPerSide + j;
                    int bottomRight = (i + 1) * pointPerSide + j + 1;
                    ans += disjoint(parentArr, topLeft, bottomRight);
                }
            }
        }
        
        return ans;
    }
};