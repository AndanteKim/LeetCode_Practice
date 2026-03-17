class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> prevRow(n);
        for (int i = 0; i < m; ++i) {
            vector<int> currRow(matrix[i].begin(), matrix[i].end());
            for (int j = 0; j < n; ++j) {
                if (currRow[j]) currRow[j] += prevRow[j];
            }

            vector<int> sortedRow = currRow;
            sort(sortedRow.begin(), sortedRow.end(), greater());
            for (int k = 0; k < n; ++k) {
                ans = max(ans, (k + 1) * sortedRow[k]);
            }

            prevRow = currRow;
        }

        return ans;
    }
};