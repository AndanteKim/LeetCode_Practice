class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int cnt = 0;
        if (mat.size() == 0 || mat.size() * mat[0].size() != r * c) return mat;
        
        vector<vector<int>> ans(r, vector<int> (mat.size() * mat[0].size() / r, 0));
        
        for (int i = 0; i < mat.size(); ++i){
            for (int j = 0; j < mat[0].size(); ++j){
                ans[cnt / c][cnt % c] = mat[i][j];
                ++cnt;
            }
        }
        
        return ans;
    }
};