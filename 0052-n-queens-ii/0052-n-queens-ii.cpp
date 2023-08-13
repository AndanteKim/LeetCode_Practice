class Solution {
private:
    int n;
    int backtrack(int row, int diagonals, int antiDiagonals, int cols){
        if (row == n) return 1;
        int solutions = 0;
        for (int col = 0; col < n; ++col){
            int currDiagonal = 1 << (row - col + n);
            int currAntiDiagonal = 1 << (row + col);
            int currCol = 1 << col;
            
            if (currCol & cols || currDiagonal & diagonals || currAntiDiagonal & antiDiagonals) continue;
            
            diagonals ^= currDiagonal;
            antiDiagonals ^= currAntiDiagonal;
            cols ^= currCol;
            
            solutions += backtrack(row + 1, diagonals, antiDiagonals, cols);
            
            diagonals ^= currDiagonal;
            antiDiagonals ^= currAntiDiagonal;
            cols ^= currCol;
        }
        
        return solutions;
    }
    
public:
    int totalNQueens(int n) {
        this -> n = n;
        return backtrack(0, 0, 0, 0);
    }
};