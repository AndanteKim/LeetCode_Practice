class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> flatten(m * n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) flatten[i * n + j] = grid[i][j];
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) ans[i][j] = flatten[(i * n + j - (k % (m * n)) + (m * n)) % (m * n)];
        }

        return ans;
    }
};