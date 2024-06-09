class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<int>> rows(n, vector<int>(n)), cols(n, vector<int>(n)), boxes(n, vector<int>(n));
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == '.') continue;
                
                int pos = (int)(board[i][j] - 48) - 1;
                
                // Check the rows
                if (rows[i][pos] == 1)
                    return false;
                rows[i][pos] = 1;
                
                // Check the columns
                if (cols[j][pos] == 1)
                    return false;
                cols[j][pos] = 1;
                
                // Check the boxes
                int boxesIdx = (i / 3) * 3 + (j / 3);
                if (boxes[boxesIdx][pos] == 1)
                    return false;
                boxes[boxesIdx][pos] = 1;
            }
        }
        
        return true;
    }
};