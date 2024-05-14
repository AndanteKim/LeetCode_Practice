class Solution {
private:
    int m, n;
    const int directions[5]{0, 1, 0, -1, 0};
    int bfsBacktrack(vector<vector<int>>& grid, int row, int col){
        queue<tuple<int, int, int, bitset<1024>>> queue;
        bitset<1024> visited;
        int maxGold = 0;
        visited[row * n + col] = 1;
        queue.push({row, col, grid[row][col], visited});
        
        while (!queue.empty()){
            auto [currR, currC, currG, currVis] = queue.front();
            queue.pop();
            maxGold = max(maxGold, currG);
            
            // Search for gold in each of the 4 neighbor cells
            for (int i = 0; i < 4; ++i){
                int nextR = currR + directions[i], nextC = currC + directions[i + 1];
                
                // If the next cell is in the matrix, has gold, 
                // aand has not been visited, add it to the queue
                if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n && grid[nextR][nextC] > 0 \
                   && !currVis[nextR * n + nextC]){
                    currVis[nextR * n + nextC] = 1;
                    queue.push({nextR, nextC, currG + grid[nextR][nextC], currVis});
                    currVis[nextR * n + nextC] = 0;
                }
            }
        }
        
        return maxGold;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();
        
        // Find the total amount of gold in the grid
        int totalGold = 0;
        for (int row = 0; row < m; ++row)
            for (int col = 0; col < n; ++col)
                totalGold += grid[row][col];
        
        int maxGold = 0;
        
        // Search for the path with the maximum gold starting from each cell
        for (int row = 0; row < m; ++row){
            for (int col = 0; col < n; ++col){
                if (grid[row][col] > 0){
                    maxGold = max(maxGold, bfsBacktrack(grid, row, col));
                    // If we found a path with the total gold, it's the max gold
                    if (maxGold == totalGold)
                        return totalGold;
                }
            }
        }
        
        return maxGold;
    }
};