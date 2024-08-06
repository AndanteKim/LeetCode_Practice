class Solution {
private:
    int rows, cols;
    void DFS(vector<vector<char>>& board, int row, int col){
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            return;
        
        if (board[row][col] != 'O')
            return;
        board[row][col] = 'E';
        
        // Jump to the neighbors without boundary checks
        for (auto& [ro, co] : vector<pair<int, int>>{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)})
            DFS(board, row + ro, col + co);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        
        rows = board.size(), cols = board[0].size();
        vector<pair<int, int>> borders;
        
        // Step1). retrieve all border cells
        for (int i = 0; i < rows; ++i){
            borders.push_back({i, 0});
            borders.push_back({i, cols - 1});
        }
        
        for (int j = 0; j < cols; ++j){
            borders.push_back({0, j});
            borders.push_back({rows - 1, j});
        }
        
        // Step2). mark the 'escaped' cell, with any placeholder, e.g. 'E'
        for (auto& [r, c] : borders)
            DFS(board, r, c);
        
        // Step3). flip the captured cells ('O' -> 'X') and the escaped one ('E' -> 'O')
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (board[i][j] == 'O')
                    board[i][j] = 'X';  // captured
                
                if (board[i][j] == 'E')
                    board[i][j] = 'O';  // escaped
            }
        }
    }
};