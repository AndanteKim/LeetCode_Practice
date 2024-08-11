class Solution {
private:
    struct ArticulationPointInfo{
        bool hasArticulationPoint = false;
        int time;
        
        ArticulationPointInfo(bool hasArticulationPoint, int time) : hasArticulationPoint(hasArticulationPoint), \
            time(time) {}
    };
    int m, n;
    
    // Directions for adjacent cells: up, down, right, left
    const vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void findArticulationPoints(int row, int col, vector<vector<int>>& discoveryTime, vector<vector<int>>& lowestReachable, vector<vector<int>>& parentCell, vector<vector<int>>& grid, ArticulationPointInfo& apInfo){
        discoveryTime[row][col] = apInfo.time;
        ++apInfo.time;
        lowestReachable[row][col] = discoveryTime[row][col];
        int children = 0;
        
        // Explore all adjacent cells
        for (auto& [dr, dc] : directions){
            int newR = row + dr, newC = col + dc;
            if (0 <= newR && newR < m && 0 <= newC && newC < n && grid[newR][newC] == 1){
                if (discoveryTime[newR][newC] == -1){
                    ++children;
                    // Set parent
                    parentCell[newR][newC] = row * n + col;
                    
                    findArticulationPoints(newR, newC, discoveryTime, lowestReachable, parentCell, grid, apInfo);
                    
                    // Update the lowest reachable time
                    lowestReachable[row][col] = min(lowestReachable[row][col], \
                                                   lowestReachable[newR][newC]);
                    
                    // Check for articulation point condition
                    if (lowestReachable[newR][newC] >= discoveryTime[row][col] &&\
                       parentCell[row][col] != -1)
                        apInfo.hasArticulationPoint = true;
                }
                else if (newR * n + newC != parentCell[row][col]){
                    // Update the lowest reachable time for back edge
                    lowestReachable[row][col] = min(lowestReachable[row][col],\
                                                       discoveryTime[newR][newC]);
                }
            }
        }
        
        // Root of DFS tree is an articulation point if it has more than one child
        if (parentCell[row][col] == -1 && children > 1)
            apInfo.hasArticulationPoint = true;
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();
        ArticulationPointInfo apInfo(false, 0);
        int landCells = 0, islandCount = 0;
        
        // Arrays to store information for each cell
        // discoveryTime := Time when a cell is first discovered
        // lowestReachable := Lowest discovery time reachable from the subtree rooted at this cell.
        // parentCell := Parent of each cell in DFS tree
        vector discoveryTime(m, vector<int>(n, -1)), lowestReachable(m, vector<int>(n, - 1)), \
            parentCell(m, vector<int>(n, -1));
        
        // Traverse the grid to find islands and articulation points
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j]){
                    ++landCells;
                    
                    // If not yet visited
                    if (discoveryTime[i][j] == -1){
                        // Start DFS for a new island
                        findArticulationPoints(i, j, discoveryTime, lowestReachable, parentCell, grid, apInfo);
                        ++islandCount;
                    }
                }
            }
        }
        
        // Determine the minimum number of days to disconnect the grid
        if (islandCount == 0 || islandCount >= 2)
            return 0;   // Already disconnected or no land
        
        if (landCells == 1)
            return 1;    // Only one land cell
        
        if (apInfo.hasArticulationPoint)
            return 1;   // An articulation point exists
        
        return 2;   // Need to remove any two land cells
    }
};