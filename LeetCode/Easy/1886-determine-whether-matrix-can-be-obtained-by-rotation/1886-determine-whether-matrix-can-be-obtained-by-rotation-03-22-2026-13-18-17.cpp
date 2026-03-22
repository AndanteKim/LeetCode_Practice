class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int topLeft, topRight, bottomLeft, bottomRight;

        for (int k = 0; k < 4; ++k) {
            for (int i = 0; i < (m >> 1); ++i) {
                for (int j = 0; j < ((m + 1) >> 1); ++j) {
                    topLeft = mat[i][j];
                    topRight = mat[j][m - 1 - i];
                    bottomLeft = mat[m - 1 - j][i];
                    bottomRight = mat[m - 1 - i][m - 1 - j];

                    mat[i][j] = bottomLeft;
                    mat[j][m - 1 - i] = topLeft;
                    mat[m - 1 - i][m - 1 - j] = topRight;
                    mat[m - 1 - j][i] = bottomRight;
                }
            }

            if (mat == target) return true;
        }

        return false;
    }
};