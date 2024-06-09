class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        
        // Use hash set to record the status
        unordered_set<char> rows[n], cols[n], boxes[n];
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                char val = board[i][j];
                
                // Check if the position is filled with number
                if (val == '.') continue;
                
                // Check the row
                if (rows[i].contains(val))
                    return false;
                rows[i].insert(val);
                
                // Check the column
                if (cols[j].contains(val))
                    return false;
                cols[j].insert(val);
                
                // Check the box
                int boxesIdx = (i / 3) * 3 + (j / 3);
                if (boxes[boxesIdx].contains(val))
                    return false;
                boxes[boxesIdx].insert(val);
            }
        }
        
        return true;
    }
};