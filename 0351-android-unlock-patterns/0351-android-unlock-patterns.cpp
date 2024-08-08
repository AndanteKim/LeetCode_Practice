class Solution {
private:
    // All possible sing-step moves on the lock pattern grid
    // Each array represents a move as {row change, column change}
    const vector<pair<int, int>> SINGLE_STEP_MOVES{
        // Adjacent moves (right, left, down, up)
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},\
        // Diagonal moves
        {-1, -1}, {1, 1}, {-1, 1}, {1, -1},\
        
        // Extended moves (knight-like moves)
        {2, -1}, {2, 1}, {-2, -1}, {-2, 1},\
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    // Moves that require a dot to be visited in between
    // These moves "jump" over a dot, which must have been previously visited
    const vector<pair<int, int>> SKIP_DOT_MOVES{
        // Straight skip moves (e.g., 1 to 3, 4 to 6)
        {2, 0}, {-2, 0}, {0, 2}, {0, -2},\
        
        // Diagonal skip moves (e.g., 1 to 9, 3 to 7)
        {-2, -2}, {2, 2}, {-2, 2}, {2, -2}
    };
    
    int m, n;
    
    // Helper method to check if a move is valid
    bool isValid(int row, int col, vector<vector<bool>>& visited){
        // A move is valid if it's within the grid and the dot hasn't been
        // visited
        return 0 <= row && row < 3 && 0 <= col && col < 3 && !visited[row][col];
    }
    
    int countPatternsFromDot(int currLength, int currRow, int currCol, vector<vector<bool>>& visited){
        // Base case: If current pattern length exceeds n, stop exploring
        if (currLength > n)
            return 0;
        
        int validPatterns = 0;
        // If current pattern length within the valid range, count it.
        if (currLength >= m)
            ++validPatterns;
        
        // Mark current dot as visited
        visited[currRow][currCol] = true;
        
        // Explore all single-step moves
        for (auto& [dr, dc] : SINGLE_STEP_MOVES){
            int newRow = currRow + dr, newCol = currCol + dc;
            if (isValid(newRow, newCol, visited))
                // Recursively count patterns from the new position
                validPatterns += countPatternsFromDot(currLength + 1, newRow, newCol, visited);
        }
        
        // Explore all skip-dot moves
        for (auto& [dr, dc] : SKIP_DOT_MOVES){
            int newRow = currRow + dr, newCol = currCol + dc;
            
            if (isValid(newRow, newCol, visited)){
                // Check if the middle dot has been visited
                int midRow = currRow + (dr >> 1), midCol = currCol + (dc >> 1);
                if (visited[midRow][midCol])
                    // If middle dot is visited, this move is valid
                    validPatterns += countPatternsFromDot(currLength + 1, newRow, newCol, visited);
            }
        }
        
        // Backtrack: unmark the current dot before returning
        visited[currRow][currCol] = false;
        return validPatterns;
    }
        
public:
    int numberOfPatterns(int m, int n) {
        int ans = 0;
        this -> m = m, this -> n = n;
        
        // Start from each of the 9 dots on the grid
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                vector<vector<bool>> visited(3, vector<bool>(3));
                // Count patterns starting from this dot
                ans += countPatternsFromDot(1, i, j, visited);
            }
        }
        
        return ans;
    }
};