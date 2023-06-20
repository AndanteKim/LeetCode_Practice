class Solution {
private:
    bool arr[7][7] = {0};
    bool ans(vector<vector<char>>& board, int m, int n, string& s, int i, int j, int pos){
        if (pos == s.size()) return true;
        if (i >= m || i < 0 || j >= n || j < 0 || board[i][j] != s[pos] || arr[i][j] == 1) return false;
        arr[i][j] = 1;
        bool top = ans(board, m, n, s, i - 1, j, pos + 1);
        bool down = ans(board, m, n, s, i + 1, j, pos + 1);
        bool left = ans(board, m, n, s, i, j + 1, pos + 1);
        bool right = ans(board, m, n, s, i, j - 1, pos + 1);
        arr[i][j] = 0;
        return top || down || left || right;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int first = 0, last = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == word[0]) ++first;
                else if (board[i][j] == word[word.size() - 1]) ++last; 
            }
        }
        
        if (first > last) reverse(word.begin(), word.end());
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == word[0]){
                    if (ans(board, m, n, word, i, j, 0)) return true;
                }
            }
        }
        
        return false;
    }
};