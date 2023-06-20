class Solution {
private:
    int m, n;
    bool valid(int r, int c){
        return 0 <= r && r < m && 0 <= c && c < n;
    }
    
    bool backtrack(int row, int col, int start, vector<vector<bool>>& seen, string& word, vector<vector<char>>& board){
        if (start == word.size()) return true;
        
        for (auto& [n_r, n_c] : vector<pair<int, int>>{{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}}){
            if (valid(n_r, n_c) && !seen[n_r][n_c]){
                if (board[n_r][n_c] == word[start]){
                    seen[n_r][n_c] = true;
                    if (backtrack(n_r, n_c, start + 1, seen, word, board)) return true;
                    seen[n_r][n_c] = false;
                }
            }
        }
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int row = 0; row < m; ++row){
            for (int col = 0; col < n; ++col){
                visited[row][col] = true;
                if (board[row][col] == word[0] && backtrack(row, col, 1, visited, word, board)) return true;
                visited[row][col] = false;
            }
        }
        
        return false;
    }
};