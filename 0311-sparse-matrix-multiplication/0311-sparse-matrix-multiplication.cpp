class SparseMatrix{
public:
    int cols = 0, rows = 0;
    vector<int> values, colIndex, rowIndex;
    
    SparseMatrix(vector<vector<int>>& matrix){
        rows = matrix.size();
        cols = matrix[0].size();
        rowIndex.push_back(0);
        
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                if (matrix[row][col]){
                    values.push_back(matrix[row][col]);
                    colIndex.push_back(col);
                }
            }
            rowIndex.push_back(values.size());
        }
    }
    
    SparseMatrix(vector<vector<int>>& matrix, bool colWise){
        rows = matrix.size();
        cols = matrix[0].size();
        colIndex.push_back(0);
        
        for (int col = 0; col < cols; ++col){
            for (int row = 0; row < rows; ++row){
                if (matrix[row][col]){
                    values.push_back(matrix[row][col]);
                    rowIndex.push_back(row);
                }
            }
            colIndex.push_back(values.size());
        }
    }
};


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        SparseMatrix A(mat1);
        SparseMatrix B(mat2, true);
        
        vector<vector<int>> ans(mat1.size(), vector<int>(mat2[0].size(), 0));
        
        for (int row = 0; row < ans.size(); ++row){
            for (int col = 0; col < ans[0].size(); ++col){
                int matrixOneRowStart = A.rowIndex[row];
                int matrixOneRowEnd = A.rowIndex[row + 1];
                
                int matrixTwoColStart = B.colIndex[col];
                int matrixTwoColEnd = B.colIndex[col + 1];
                
                while (matrixOneRowStart < matrixOneRowEnd && matrixTwoColStart < matrixTwoColEnd){
                    if (A.colIndex[matrixOneRowStart] < B.rowIndex[matrixTwoColStart]) ++matrixOneRowStart;
                    else if (A.colIndex[matrixOneRowStart] > B.rowIndex[matrixTwoColStart]) ++matrixTwoColStart;
                    else{
                        ans[row][col] += A.values[matrixOneRowStart] * B.values[matrixTwoColStart];
                        ++matrixOneRowStart;
                        ++matrixTwoColStart;
                    }
                }
            }
        }
        
        return ans;
    }
};