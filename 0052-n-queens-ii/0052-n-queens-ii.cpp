class Solution {
    int n;
    
    int backtrack(int row, unordered_set<int>& diagonals, unordered_set<int>& antiDiagonals, unordered_set<int>& cols){
        if (row == n) return 1;
        int ans = 0;
        for (int col = 0; col < n; ++col){
            int currDiagonal = row - col, currAntiDiagonal = row + col;
            
            if (cols.find(col) != cols.end() || diagonals.find(currDiagonal) != diagonals.end() || antiDiagonals.find(currAntiDiagonal) != antiDiagonals.end()) continue;
            cols.insert(col);
            diagonals.insert(currDiagonal);
            antiDiagonals.insert(currAntiDiagonal);
            ans += backtrack(row + 1, diagonals, antiDiagonals, cols);
            cols.erase(col);
            diagonals.erase(currDiagonal);
            antiDiagonals.erase(currAntiDiagonal);
        }
        
        return ans;
    }
    
public:
    int totalNQueens(int n) {
        this -> n = n;
        unordered_set<int> diagonals, antiDiagonals, cols;
        return backtrack(0, diagonals, antiDiagonals, cols);
    }
};