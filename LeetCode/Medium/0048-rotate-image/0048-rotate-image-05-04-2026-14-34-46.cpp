class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();

        for (int i = 0; i < (n >> 1) + n % 2; ++i) {
            for (int j = 0; j < (n >> 1); ++j) {
                int tmp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
};