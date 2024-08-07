class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        // Use binary number to check previous occurrence
        int rows[n]{0}, cols[n]{0}, boxes[n]{0};
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                // Check if the position is filled with number
                if (board[i][j] == '.') continue;
                
                int pos = board[i][j] - '1';
                
                // Check the row
                if (rows[i] & (1 << pos))
                    return false;
                rows[i] |= (1 << pos);
                
                // Check the column
                if (cols[j] & (1 << pos))
                    return false;
                cols[j] |= (1 << pos);
                
                // Check the boxes
                int boxesIdx = (i / 3) * 3 + (j / 3);
                if (boxes[boxesIdx] & (1 << pos))
                    return false;
                boxes[boxesIdx] |= (1 << pos);
            }
        }
        
        return true;
    }
};