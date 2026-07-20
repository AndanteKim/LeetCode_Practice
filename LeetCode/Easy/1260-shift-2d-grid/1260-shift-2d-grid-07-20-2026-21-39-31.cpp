class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        for (int _ = 0; _ < k; ++_) {
            int prev = grid.back().back();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int temp = grid[i][j];
                    grid[i][j] = prev;
                    prev = temp;
                }
            }
        }

        return grid;
    }
};