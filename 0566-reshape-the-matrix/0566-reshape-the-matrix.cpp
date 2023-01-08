class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = 0, col = 0;
        if (mat.size() * mat[0].size() != r * c) return mat;
        
        vector<vector<int>> ans(r, vector<int> (mat.size() * mat[0].size() / r, 0));
        
        for (int i = 0; i < ans.size(); ++i){
            for (int j = 0; j < ans[0].size(); ++j){
                ans[i][j] = mat[row][col];
                if (col == mat[0].size() - 1){
                    ++row;
                    col = 0;
                }
                else ++col;
            }
        }
        
        return ans;
    }
};