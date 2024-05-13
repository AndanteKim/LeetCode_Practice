class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Set the first column for flip
        for (int i = 0; i < m; ++i){
            if (grid[i][0] == 0){
                for (int j = 0; j < n; ++j){
                    grid[i][j] = 1 - grid[i][j]; // Bitwise XOR for flip
                }
            }
        }
        
        // Optimize the column after the first column
        for (int j = 0; j < n; ++j){
            int countZero = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 0) ++countZero;
            }
            
            if (countZero > m - countZero){
                for (int i = 0; i < m; ++i)
                    grid[i][j] ^= 1; // Bitwise XOR for flip
            }
        }
        
        // Calculate the final score considering bit positions
        int ans = 0;
        for (int i = 0; i < m; ++i){
            int columnScore = 0;
            for (int j = 0; j < n; ++j)
                // Left shift bit by place value of column to find column contribution.
                columnScore += grid[i][j] << (n - j - 1);
            // Add contribution to score
            ans += columnScore;
        }
       
        // return the final ans
        return ans;
    }
};