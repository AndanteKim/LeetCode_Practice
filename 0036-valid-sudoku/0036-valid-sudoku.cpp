class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int rows[n][n], cols[n][n], boxes[n][n];
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxes, 0, sizeof(boxes));
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                // Check if the position is filled with number
                if (board[i][j] == '.') continue;
                
                int pos = board[i][j] - '1';
                
                // Check the row
                if (rows[i][pos] == 1)
                    return false;
                rows[i][pos] = 1;
                
                // Check the column
                if (cols[j][pos] == 1)
                    return false;
                cols[j][pos] = 1;
                
                // Check the box
                int boxesIdx = (i / 3) * 3 + (j / 3);
                if (boxes[boxesIdx][pos] == 1)
                    return false;
                boxes[boxesIdx][pos] = 1;
            }
        }
        
        return true;
    }
};