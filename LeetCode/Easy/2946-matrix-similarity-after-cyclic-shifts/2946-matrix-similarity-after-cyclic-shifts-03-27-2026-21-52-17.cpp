class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k = (k % 2)? k % n : -(k % n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][(n + j + k) % n] != mat[i][j]) return false;
            }
        }

        return true;
    }
};