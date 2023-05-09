class Solution {
    vector<vector<pair<int, int>>> compressMatrix(vector<vector<int>>& matrix){
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<pair<int, int>>> compressedMatrix(rows);
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                if (matrix[row][col])
                    compressedMatrix[row].push_back({matrix[row][col], col});
            }
        }
        return compressedMatrix;
    }
    
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();
        vector<vector<pair<int, int>>> A = compressMatrix(mat1), B = compressMatrix(mat2);
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int mat1Row = 0; mat1Row < m; ++mat1Row){
            for (auto [element1, mat1Col] : A[mat1Row]){
                for (auto [element2, mat2Col] : B[mat1Col]){
                    ans[mat1Row][mat2Col] += element1 * element2;
                }
            }
        }
        
        return ans;
    }
};