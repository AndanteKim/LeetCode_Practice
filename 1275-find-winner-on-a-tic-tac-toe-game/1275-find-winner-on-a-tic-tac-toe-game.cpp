class Solution {
private:
    int n;
    // check if any of 4 winning condittions to see if the current player has won
    bool checkRow(int row, int playerId, vector<vector<int>>& board){
        for (int col = 0; col < n; ++col)
            if (board[row][col] != playerId)
                return false;
        return true;
    }
    
    bool checkCol(int col, int playerId, vector<vector<int>>& board){
        for (int row = 0; row < n; ++row)
            if (board[row][col] != playerId)
                return false;
        return true;
    }
    
    bool checkDiagonal(int playerId, vector<vector<int>>& board){
        for (int row = 0; row < n; ++row)
            if (board[row][row] != playerId)
                return false;
        return true;
    }
    
    bool checkAntiDiagonal(int playerId, vector<vector<int>>& board){
        for (int row = 0; row < n; ++row)
            if (board[row][n - 1 - row] != playerId)
                return false;
        return true;
    }
    
public:
    string tictactoe(vector<vector<int>>& moves) {
        this -> n = 3;
        int player = 1;
        vector<vector<int>> board(n, vector<int>(n));
        for (vector<int>& move : moves){
            int row = move[0] , col = move[1];
            board[row][col] = player;
            
            // If any of the winning conditions is met, return the current player's id
            if (checkRow(row, player, board) || checkCol(col, player, board) ||\
               (row == col && checkDiagonal(player, board)) || \
               (row + col == n - 1 && checkAntiDiagonal(player, board)))
                return player == 1? "A" : "B";
            
            // If no one wins so far, change to the other player alternatively
            player *= -1;
        }
        
        //If all moves are completed and there is no still result, we shall check if the grid is\
        //full or not.        
        return moves.size() == n * n? "Draw" : "Pending";
    }
};