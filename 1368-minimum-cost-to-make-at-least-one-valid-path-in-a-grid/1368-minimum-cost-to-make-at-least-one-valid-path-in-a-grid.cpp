class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Initialize all cells with max value
        vector minCost(m, vector<int>(n, numeric_limits<int>::max()));
        minCost[0][0] = 0;

        while (true){
            // Store previous state to check for convergence
            vector<vector<int>> prev = minCost;
            
            // Forward pass: check cells coming from left and top
            for (int row = 0; row < m; ++row){
                for (int col = 0; col < n; ++col){
                    // Check the cell above
                    if (row > 0){
                        minCost[row][col] = min(
                            minCost[row][col],
                            minCost[row - 1][col] + (grid[row - 1][col] == 3? 0 : 1)
                        );
                    }

                    // Check the cell to the left
                    if (col > 0){
                        minCost[row][col] = min(
                            minCost[row][col],
                            minCost[row][col - 1] + (grid[row][col - 1] == 1? 0 : 1)
                        );
                    }
                }
            }

            // Backward pass: check cells coming from right and bottom
            for (int row = m - 1; row >= 0; --row){
                for (int col = n - 1; col >= 0; --col){
                    // Check cell below
                    if (row < m - 1){
                        minCost[row][col] = min(
                            minCost[row][col],
                            minCost[row + 1][col] + (grid[row + 1][col] == 4? 0 : 1)
                        );
                    }
                    
                    // Check cell to the right
                    if (col < n - 1){
                        minCost[row][col] = min(
                            minCost[row][col],
                            minCost[row][col + 1] + (grid[row][col + 1] == 2? 0 : 1)
                        );
                    }
                }
            }

            // If no changes were made in this iteration, we've found optimal solution
            if (prev == minCost)
                break;
        }

        return minCost[m - 1][n - 1];
    }
};