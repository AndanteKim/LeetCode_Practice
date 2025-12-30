class Solution {
private:
    int m, n;
    
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        vector<bool> seen(10);

        for (int i = row; i < row + 3; ++i) {
            for (int j = col; j < col + 3; ++j){
                if (grid[i][j] < 1 || grid[i][j] > 9) return false;
                if (seen[grid[i][j]]) return false;

                seen[grid[i][j]] = true;
            }
        }

        // Check whether the magic number is 15.
        int dia1 = (
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]
            );
        int dia2 = (
            grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2]
        );

        if (dia1 != dia2) return false;

        for (int i = row; i < row + 3; ++i) {
            int rowSum = 0;
            for (int j = col; j < col + 3; ++j) {
                rowSum += grid[i][j];
            }
            if (rowSum != dia1 || rowSum != dia2) return false;
        }

        for (int j = col; j < col + 3; ++j) {
            int colSum = 0;
            for (int i = row; i < row + 3; ++i)
                colSum += grid[i][j];
            
            if (colSum != dia1 || colSum != dia2) return false;
        }

        return true;
    }


public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();

        // Base case
        if (m < 3 || n < 3) return 0;
        
        int ans = 0;

        for (int row = 0; row < m - 2; ++row){
            for (int col = 0; col < n - 2; ++col) {
                if (isMagicSquare(grid, row, col)) ++ans;
            }
        }    

        return ans;
    }
};