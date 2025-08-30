class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] != '.'){
                    if (rows[i].count(board[i][j]) || cols[j].count(board[i][j])) return false;
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                }
            }
        }

        for (int currCube = 0; currCube < 9; ++currCube){
            int startRow = (currCube / 3) * 3, startCol = (3 * currCube) % 9;
            unordered_set<char> seen;
            for (int row = startRow; row < startRow + 3; ++row){
                for (int col = startCol; col < startCol + 3; ++col){
                    if (board[row][col] != '.'){
                        if (seen.count(board[row][col])) return false;
                        seen.insert(board[row][col]);
                    }
                }
            }
        }
        
        return true;
    }
};