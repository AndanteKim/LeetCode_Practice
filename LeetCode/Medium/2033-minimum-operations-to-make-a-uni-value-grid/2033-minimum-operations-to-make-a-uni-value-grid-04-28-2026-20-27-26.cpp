class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> elems(m * n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) elems[i * n + j] = grid[i][j];
        }

        sort(elems.begin(), elems.end());
        int median = ((m * n) % 2 == 0)? ((m * n) >> 1) - 1 : ((m * n) >> 1);
        int avg = elems[median], ans = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j){
                if (abs(grid[i][j] - avg) % x != 0) return -1;
                ans += abs(grid[i][j] - avg) / x;
            }
        }

        return ans;
    }
};