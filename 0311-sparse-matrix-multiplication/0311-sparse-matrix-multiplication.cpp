class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int row1 = mat1.size(), col1 = mat1[0].size(), row2 = mat2.size(), col2 = mat2[0].size();

        vector ans(row1, vector<int>(col2, 0));
        for (int i = 0; i < row1; ++i){
            for (int j = 0; j < col2; ++j){
                int curr = 0;
                for (int k = 0; k < col1; ++k)
                    curr += mat1[i][k] * mat2[k][j];
                ans[i][j] = curr;
            }
        }

        return ans;
    }
};