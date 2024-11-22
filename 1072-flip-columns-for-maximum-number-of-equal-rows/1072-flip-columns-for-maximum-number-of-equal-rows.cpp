class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxIdenticalRows = 0;
        
        for (auto& currRow : matrix){
            // Create a vector to store flipped version of current row
            vector<int> flippedRows(n);
            
            // Flipped version of current row by XOR operator
            for (int i = 0; i < n; ++i)
                flippedRows[i] = currRow[i] ^ 1;
            
            int identicalRowCount = 0;
            
            // Check every row against current row and its flipped version
            for (auto& compareRow : matrix){
                // If row matches either original or flipped pattern, increment
                // counter
                if (compareRow == currRow || compareRow == flippedRows)
                    ++identicalRowCount;
            }
            
            maxIdenticalRows = max(maxIdenticalRows, identicalRowCount);
        }
        
        return maxIdenticalRows;
    }
};