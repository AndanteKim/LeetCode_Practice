class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if (mat.size() == 1) return mat[0][0];
        int ans = 0, length = mat.size();
        if (length % 2 == 0){
            for (int i = 0; i < mat.size(); ++i) ans += mat[i][i], ans += mat[length - 1 - i][i];
        }
        else{
            for (int i = 0; i < mat.size(); ++i) ans += mat[i][i], ans += mat[length - 1 - i][i];
            ans -= mat[length/2][length/2];
        }
        return ans;
    }
};