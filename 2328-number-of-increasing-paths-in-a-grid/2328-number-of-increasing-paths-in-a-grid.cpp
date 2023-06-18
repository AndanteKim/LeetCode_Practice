class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mod = 1'000'000'007;
        int d[5] = {-1, 0, 1, 0, -1};
        vector<vector<int>> indeg(m, vector<int>(n));
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                for (int k = 0; k < 4; ++k){
                    int ii = i + d[k], jj = j + d[k + 1];
                    if (0 <= ii && ii < m && 0 <= jj && jj < n && grid[i][j] < grid[ii][jj])
                        ++indeg[i][j];
                }
            }
        }
        
        queue<pair<int, int>> queue;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (indeg[i][j] == 0) queue.emplace(i, j);
            }
        }
        
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        while (!queue.empty()){
            auto [i, j] = queue.front();
            queue.pop();
            ans = (ans + dp[i][j]) % mod;
            for (int k = 0; k < 4; ++k){
                int ii = i + d[k], jj = j + d[k + 1];
                if (0 <= ii && ii < m && 0 <= jj && jj < n){
                    if (grid[i][j] > grid[ii][jj]){
                        dp[ii][jj] = (dp[i][j] + dp[ii][jj]) % mod;
                        if (--indeg[ii][jj] == 0) queue.emplace(ii, jj);
                    }
                }
            }
        }
        
        return ans;
    }
};