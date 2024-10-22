class Solution {
private:
    int m, n;
    // Possible knight moves: (row, column) pairs
    vector<pair<int, int>> knightMoves{
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, -2}, {-1, 2}\
    };
    bool isValidMove(int row, int col, vector<vector<int>>& board){
        return 0 <= row && row < m && 0 <= col && col < n && board[row][col] == 0;
    }
    
    // Implement Warnsdorff's rule: prefer moves with fewer onward moves
    void getNextMoveWarnsdorff(int row, int col, vector<vector<int>>& board, vector<pair<int, int>>& nextMoves){
        for (int index = 0; index < 8; ++index){
            int nextRow = row + knightMoves[index].first, nextCol = col + knightMoves[index].second;
            if (!isValidMove(nextRow, nextCol, board)) continue;
            
            int accessibilityScore = 0;
            for (const auto& [dr, dc] : knightMoves)
                if (isValidMove(nextRow + dr, nextCol + dc, board)) ++accessibilityScore;
            
            nextMoves.push_back({accessibilityScore, index});
        }
        
        // Sort moves based on accessibility (fewer accessible squares first)
        sort(nextMoves.begin(), nextMoves.end());
    }
    
    bool solve(int row, int col, int count, vector<vector<int>>& board){
        // Base case: If all cells are visited, we've found a solution.
        if (count == m * n)
            return true;
        
        // Get and sort possible next moves based on Warnsdorff's rule
        vector<pair<int, int>> nextMoves;
        getNextMoveWarnsdorff(row, col, board, nextMoves);
        
        // Try each possible move
        for (auto& [_, index] : nextMoves){
            int newRow = row + knightMoves[index].first, newCol = col + knightMoves[index].second;
            if (isValidMove(newRow, newCol, board)){
                // Recursively try to solve from this new position
                board[newRow][newCol] = count;
                if (solve(newRow, newCol, count + 1, board))
                    return true;
                
                // If the move doesn't lead to a solution, backtrack
                board[newRow][newCol] = 0;
            }
        }
        
        // No solution found from this position
        return false;
    }
    
public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        this -> m = m, this -> n = n;
        vector board(m, vector<int>(n, 0));
        board[r][c] = -1;
        solve(r, c, 1, board);
        // Reset starting position to 0
        board[r][c] = 0;
        return board;
    }
};