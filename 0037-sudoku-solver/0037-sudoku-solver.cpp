class Solution {
private:
    // box size
    int n = 3;
    // row size
    int N = n * n;
    bool sudokuSolved = false;
    int boxIndices(int row, int col){
        return ((row / n) * n) + (col / n);
    }
    
    bool couldPlace(int d, int row, int col, vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& boxes){
        return rows[row][d] + cols[col][d] + boxes[boxIndices(row, col)][d] == 0;
    }
    
    void placeNumber(int d, int row, int col, vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& boxes, vector<vector<char>>& board){
        ++rows[row][d];
        ++cols[col][d];
        ++boxes[boxIndices(row, col)][d];
        board[row][col] = d + 48;
    }
    
    void removeNumber(int d, int row, int col, vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& boxes, vector<vector<char>>& board){
        // remove numbers not leading to a solution.
        --rows[row][d];
        --cols[col][d];
        --boxes[boxIndices(row, col)][d];
        board[row][col] = '.';
    }
    
    void placeNextNumbers(int row, int col, vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& boxes, vector<vector<char>>& board){
        // call backtrack function in recursion to continue to place number until the moment we have a solution.
        if (col == N - 1 && row == N - 1) sudokuSolved = true;
        else{
            if (col == N - 1) backtrack(row + 1, 0, rows, cols, boxes, board);
            else backtrack(row, col + 1, rows, cols, boxes, board);
        }
    }
    
    void backtrack(int row, int col, vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& boxes, vector<vector<char>>& board){
        if (board[row][col] == '.'){
            for (int d = 1; d <= 9; ++d){
                if (couldPlace(d, row, col, rows, cols, boxes)) {
                    placeNumber(d, row, col, rows, cols, boxes, board);
                    placeNextNumbers(row, col, rows, cols, boxes, board);
                    // If sudoku is solved, then there is no need to backtrack since there exists one unique solution
                    if (!sudokuSolved) removeNumber(d, row, col, rows, cols, boxes, board);
                }
            }
        }
        else placeNextNumbers(row, col, rows, cols, boxes, board);
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(N, vector<int>(N + 1)), cols(N, vector<int>(N + 1)), boxes(N, vector<int>(N + 1));
        
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                if (board[i][j] != '.'){
                    int d = board[i][j] - '0';
                    placeNumber(d, i, j, rows, cols, boxes, board);
                }
            }
        }
    
        backtrack(0, 0, rows, cols, boxes, board);
    }
};