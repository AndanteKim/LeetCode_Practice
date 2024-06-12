class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // Neighbors array to find 8 neighboring cells for a given cell.
        vector<pair<int, int>> neighbors{{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1},\
        {-1, 0}, {-1, 1}};
        int rows = board.size(), cols = board[0].size();
        
        // Iterate through board cell by cell
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                // For each cell, count the number of live neighbors
                int r, c, liveNeighbors = 0;
                for (auto& [dr, dc] : neighbors){
                    r = row + dr;
                    c = col + dc;
                    
                    // Check the validity of the neighboring cell and if it was originally a live cell.
                    if (r >= 0 && r < rows && c >= 0 && c < cols && abs(board[r][c]) == 1)
                        ++liveNeighbors;
                }
                
                // Rules 1, 3
                if ((liveNeighbors < 2 || liveNeighbors > 3) && board[row][col] == 1)
                    // -1 signifies the cell is now dead, but was originally live
                    board[row][col] = -1;
                    
                // Rules 4
                if (liveNeighbors == 3 && board[row][col] == 0)
                    // 2 signifies the cell is now live, but was originally dead
                    board[row][col] = 2;
            }
            
        }
        
        // Get the final representation for the newly updated board.
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                if (board[row][col] > 0)
                    board[row][col] = 1;
                else
                    board[row][col] = 0;
            }
        }
    }
};