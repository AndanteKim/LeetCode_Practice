class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<vector<int>> ans(mat1.size(), vector<int>(mat2[0].size(), 0));
        for (int row1 = 0; row1 < mat1.size(); ++row1){
            for (int col1 = 0; col1 < mat1[0].size(); ++col1){
                if (mat1[row1][col1]){
                    for (int k = 0; k < mat2[col1].size(); ++k)
                        ans[row1][k] += mat1[row1][col1] * mat2[col1][k];
                }
            }
        }
        
        return ans;
    }
};