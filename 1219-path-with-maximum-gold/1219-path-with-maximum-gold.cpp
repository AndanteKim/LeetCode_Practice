class Solution {
private:
    int m, n;
    const int directions[5]{-1, 0, 1, 0, -1};
    int backtrack(vector<vector<int>>& grid, int row, int col){
        // Base case: This is not in the matrix or has no gold
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0)
            return 0;
        
        // Mark the cell as visited and save the valuue
        int originalValue = grid[row][col], maxGold = 0;
        grid[row][col] = 0;
        
        // Backtrack in each of four dirs
        for (int i = 0; i < 4; ++i)
            maxGold = max(maxGold, backtrack(grid, row + directions[i], col + directions[i + 1]));
        
        // Set the cell back to its original value
        grid[row][col] = originalValue;
        
        return maxGold + originalValue;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();
        int ans = 0;
        
        // Search for the path with the maximum gold starting from each cell
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j)
                ans = max(ans, backtrack(grid, i, j));
        }
        
        return ans;
    }
};