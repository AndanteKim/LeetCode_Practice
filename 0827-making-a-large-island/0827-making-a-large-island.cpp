class Solution {
private:
    int m, n;
    bool isValid(int row, int col, vector<vector<int>>& grid){
        return 0 <= row && row < m && 0 <= col && col < n && grid[row][col] == 1;
    }

    int exploreIslands(int islandId, int row, int col, vector<vector<int>>& grid){
        if (!isValid(row, col, grid))
            return 0;

        grid[row][col] = islandId;
        return 1 + (exploreIslands(islandId, row + 1, col, grid)\
        + exploreIslands(islandId, row - 1, col, grid)\
        + exploreIslands(islandId, row, col - 1, grid)\
        + exploreIslands(islandId, row, col + 1, grid));
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();

        // Step 1: Mark all islands and calculate their sizes
        unordered_map<int, int> islandSizes;
        int islandId = 2;
        for (int row = 0; row < m; ++row){
            for (int col = 0; col < n; ++col){
                if (grid[row][col] == 1){
                    islandSizes[islandId] = exploreIslands(islandId, row, col, grid);
                    ++islandId;
                }
            }
        }

        // If there are no islands, return 1
        if (islandSizes.empty()) return 1;

        // If the entire grid is one island, return its size or size + 1
        if (islandSizes.size() == 1){
            --islandId;
            return islandSizes[islandId] == m * n? islandSizes[islandId] : islandSizes[islandId] + 1;
        }

        int maxIslandSizes = 1;

        // Step2: Try converting every 0 to 1 and calculate the resulting island size
        for (int row = 0; row < m; ++row){
            for (int col = 0; col < n; ++col){
                if (grid[row][col] == 0){
                    int currIslandSizes = 1;
                    unordered_set<int> neighboringIslands;

                    // Check down
                    if (row + 1 < m && grid[row + 1][col] > 1)
                        neighboringIslands.insert(grid[row + 1][col]);
                    
                    // Check up
                    if (row - 1 >= 0 && grid[row - 1][col] > 1)
                        neighboringIslands.insert(grid[row - 1][col]);

                    // Check right
                    if (col + 1 < n && grid[row][col + 1] > 1)
                        neighboringIslands.insert(grid[row][col + 1]);

                    // Check left
                    if (col - 1 >= 0 && grid[row][col - 1] > 1)
                        neighboringIslands.insert(grid[row][col - 1]);
                    
                    // Sum the sizes of all unique neighboring islands
                    for (int id : neighboringIslands)
                        currIslandSizes += islandSizes[id];
                    
                    maxIslandSizes = max(maxIslandSizes, currIslandSizes);
                }
            }

        }

        return maxIslandSizes;
    }
};