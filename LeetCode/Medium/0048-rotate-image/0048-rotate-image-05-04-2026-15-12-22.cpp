class Solution {
private:
    int n;
    void transpose(vector<vector<int>>& matrix) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) swap(matrix[i][j], matrix[j][i]);
        }
    }

    void reflect(vector<vector<int>>& matrix) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (n >> 1); ++j) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        transpose(matrix);
        reflect(matrix);
    }
};