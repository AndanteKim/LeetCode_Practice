class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col){
        // The sequences are each repeated twice to account for
        // the different possible starting points of the sequence
        // in the magic square
        string sequence = "2943816729438167", sequenceRev = "7618349276183492";
        string border = "";
        
        // Flattened indices for bordering elements of 3x3 grid
        vector<int> borderIndices {0, 1, 2, 5, 8, 7, 6, 3};
        for (int i : borderIndices){
            border += to_string(grid[row + (i / 3)][col + (i % 3)]);
        }
        
        // Make sure the sequence starts at one of the corners
        return grid[row][col] % 2 == 0 && (sequence.find(border) != std::string::npos || \
                                           sequenceRev.find(border) != std::string::npos) && grid[row + 1][col + 1] == 5;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        
        for (int row = 0; row < m - 2; ++row){
            for (int col = 0; col < n - 2; ++col){
                if (isMagicSquare(grid, row, col))
                    ++ans;
            }
        }
        
        return ans;
    }
};