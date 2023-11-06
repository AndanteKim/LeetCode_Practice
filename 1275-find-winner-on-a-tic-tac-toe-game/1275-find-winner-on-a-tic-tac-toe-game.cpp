class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        // use rows and cols to record the value on each row and each column diag1 and diag2 to record value on diagonal or anti-diagonal
        int n = 3, player = 1, diagonals = 0, antiDiagonals = 0;
        vector<int> rows(n), cols(n);
        
        // 2 players having value of 1 and -1, player_1 with value = 1 places first
        for (vector<int>& move : moves){
            int row = move[0], col = move[1];
            
            // update the row value and column value
            rows[row] += player;
            cols[col] += player;
            
            // If this move is placed on diagonal or anti-diagonal, we shall update the relative value as well
            if (row == col)
                diagonals += player;
            
            if (row + col == n - 1)
                antiDiagonals += player;
            
            // check if this move meets any of the winning conditions
            for (int line : vector<int>{rows[row], cols[col], diagonals, antiDiagonals})
                if (abs(line) == n)
                    return (player == 1)? "A" : "B";
            
            // If no one wins so far, change to the other player alternatively
            // That is from 1 to -1, from -1 to 1.
            player *= -1;
        }
        
        // If all moves are completed and there is still no result, we shall check if the grid is full or not.
        // If so, the game ends with draw, otherwise pending.
        return (moves.size() == n * n)? "Draw" : "Pending";
    }
};