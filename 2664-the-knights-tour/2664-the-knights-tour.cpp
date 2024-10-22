class Solution {
private:
    int m, n;
    
    // Precompute possible knight moves
    vector<pair<int, int>> moves{{2, 1}, {2, -1}, {-2, 1}, {-2, -1},\
                                 {1, 2}, {-1, -2}, {1, -2}, {-1, 2}
                                 };
    
    bool isValidMove(int toRow, int toCol, vector<vector<int>>& board){
        return 0 <= toRow && toRow < m && 0 <= toCol && toCol < n && board[toRow][toCol] == 0;
    }
    
    bool backtrack(vector<vector<int>>& board, int currRow, int currCol, int count){
        // Base case: If all cells have been visited, we've found a solution.
        if (count == m * n) return true;
        
        // Try all possible knight moves
        for (auto& [dr, dc] : moves){
            int newRow = currRow + dr, newCol = currCol + dc;
            
            // Check if the move is valid
            if (isValidMove(newRow, newCol, board)){
                board[newRow][newCol] = count;
                
                // Recursively try to solve from this new position
                if (backtrack(board, newRow, newCol, count + 1))
                    return true;
                
                // If the move doesn't lead to a solution, backtrack
                board[newRow][newCol] = 0;
            }
        }
        
        // If no solution is found from the current position
        return false;
    }
    
public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        this -> m = m, this -> n = n;
        vector board(m, vector<int>(n));
        board[r][c] = -1;
        
        // Start the recursive solving process
        backtrack(board, r, c, 1);
        board[r][c] = 0;
        return board;
    }
};