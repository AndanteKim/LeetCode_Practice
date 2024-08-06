class Solution {
private:
    int rows, cols;
    void BFS(vector<vector<char>>& board, int row, int col){
        queue<pair<int, int>> queue;
        queue.push({row, col});
        
        while (!queue.empty()){
            auto [r, c] = queue.front(); queue.pop();
            
            if (board[r][c] != 'O')
                continue;
            
            // Mark this cell as escaped
            board[r][c] = 'E';
            // Check its neighbor cells
            if (c < cols - 1)
                queue.push({r, c + 1});
            
            if (r < rows - 1)
                queue.push({r + 1, c});
            
            if (c > 0)
                queue.push({r, c - 1});
            
            if (r > 0)
                queue.push({r - 1, c});
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        // Base case
        if (board.empty() || board[0].empty()) return;
        
        this -> rows = board.size(), this -> cols = board[0].size();
        vector<pair<int, int>> borders;
        
        // Step1). retrive all border cells
        for (int i = 0; i < rows; ++i){
            borders.push_back({i, 0});
            borders.push_back({i, cols - 1});    
        }
        
        for (int j = 0; j < cols; ++j){
            borders.push_back({0, j});
            borders.push_back({rows - 1, j});
        }
        
        // Step2). mark the "escaped" cells, with any placeholder, e.g. 'E'
        for (auto& [r, c] : borders)
            BFS(board, r, c);
        
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