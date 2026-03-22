class Solution {
private:
    int m, n;

    void rotate(vector<vector<int>>& mat) {
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < n; ++j)
                swap(mat[i][j], mat[j][i]);
            
            reverse(mat[i].begin(), mat[i].end());
        }
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        this -> m = mat.size(), this -> n = mat[0].size();

        for (int i = 0; i < 4; ++i) {
            if (mat == target) return true;
            rotate(mat);
        }

        return false;
    }
};