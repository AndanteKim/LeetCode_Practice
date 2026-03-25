class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long rowSum = 0, colSum = 0, total = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) total += grid[i][j];
        }

        if (total % 2) return false;
        long long target = total >> 1;

        for (int i = 0; i < m - 1; ++i) {
            colSum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
            if (colSum == target) return true;
        }

        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i)
                rowSum += grid[i][j];
            if (rowSum == target) return true;
        }

        return false;
    }
};