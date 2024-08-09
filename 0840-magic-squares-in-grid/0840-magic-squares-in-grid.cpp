class Solution {
private:
    int m, n;
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col){
        vector<bool> seen(10);
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9)
                    return false;
                if (seen[num]) return false;
                seen[num] = true;
            }
        }
        

        int dia = 0, antiDia = 0;
        
        // Check if diagonal sums are the same.
        for (int i = 0; i < 3; ++i){
            dia += grid[row + i][col + i];
            antiDia += grid[row + 2 - i][col + i];
        }
        
        if (dia != antiDia) return false;
        
        // Check if all row sums are the same as the diagonal sums
        vector<int> rowSum(3);
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j)
                rowSum[i] += grid[row + i][col + j];
        }
        
        for (int i = 0; i < 3; ++i) if (rowSum[i] != dia) return false;
        
        // Check if all column sums are the same as the diagonal sums
        vector<int> colSum(3);
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j)
                colSum[i] += grid[row + j][col + i];
        }
        
        for (int i = 0; i < 3; ++i) if (colSum[i] != dia) return false;
        
        return true;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();
        if (m < 3 || n < 3) return 0;
        
        int ans = 0;
        for (int i = 0; i < m - 2; ++i){
            for (int j = 0; j < n - 2; ++j){
                if (isMagicSquare(grid, i, j))
                    ++ans;
            }
        }
        
        return ans;
    }
};