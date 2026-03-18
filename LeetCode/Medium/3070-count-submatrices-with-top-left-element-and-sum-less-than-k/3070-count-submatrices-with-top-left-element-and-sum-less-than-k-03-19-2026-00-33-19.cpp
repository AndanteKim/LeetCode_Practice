class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> cols(n);

        for (int i = 0; i < m; ++i) {
            int rowSum = 0;
            for (int j = 0; j < n; ++j) {
                cols[j] += grid[i][j];
                rowSum += cols[j];
            
                if (rowSum <= k) ++ans;
            }
        }

        return ans;
    }
};