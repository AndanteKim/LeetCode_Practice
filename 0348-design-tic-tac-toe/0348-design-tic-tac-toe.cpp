class TicTacToe {
private:
    vector<int> rows, cols;
    int n, diagonal = 0, antiDiagonal = 0;
    
public:
    
    TicTacToe(int n) {
        this -> n = n;
        rows.resize(n, 0);
        cols.resize(n, 0);
    }
    
    int move(int row, int col, int player) {
        int currentPlayer = (player == 1)? 1 : -1;
        rows[row] += currentPlayer;
        cols[col] += currentPlayer;
        if (row == col) diagonal += currentPlayer;
        if (row == n - col - 1) antiDiagonal += currentPlayer;
        
        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(antiDiagonal) == n) return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */