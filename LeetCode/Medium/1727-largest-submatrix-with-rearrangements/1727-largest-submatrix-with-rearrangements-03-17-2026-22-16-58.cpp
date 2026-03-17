class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] && i > 0) matrix[i][j] += matrix[i - 1][j];
            }

            vector<int> currRow = matrix[i];
            sort(currRow.begin(), currRow.end(), [](int a, int b) {return a > b;});

            for (int k = 0; k < n; ++k) {
                ans = max(ans, currRow[k] * (k + 1));
            }
        }

        return ans;
    }
};