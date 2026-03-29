typedef long long ll;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size(), MOD = 1'000'000'007;
        vector<vector<ll>> maxgt(m, vector<ll>(n)), minlt(m, vector<ll>(n));
        maxgt[0][0] = minlt[0][0] = grid[0][0];
        
        for (int i = 1; i < n; ++i) {
            maxgt[0][i] = minlt[0][i]= maxgt[0][i - 1] * grid[0][i];
        }

        for (int i = 1; i < m; ++i) {
            maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] >= 0) {
                    maxgt[i][j] = max(maxgt[i - 1][j], maxgt[i][j - 1]) * grid[i][j];
                    minlt[i][j] = min(minlt[i - 1][j], minlt[i][j - 1]) * grid[i][j];
                }
                else {
                    maxgt[i][j] = min(minlt[i - 1][j], minlt[i][j - 1]) * grid[i][j];
                    minlt[i][j] = max(maxgt[i - 1][j], maxgt[i][j - 1]) * grid[i][j];
                }
            }
        }

        if (maxgt[m - 1][n - 1] < 0) return -1;
        return maxgt[m - 1][n - 1] % MOD;
    }
};