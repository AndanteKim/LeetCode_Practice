class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowCnt(m), colCnt(n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) {
                    ++rowCnt[i];
                    ++colCnt[j];
                }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j])
                    if (rowCnt[i] > 1 || colCnt[j] > 1) ++ans;
            }
        }

        return ans;
    }
};