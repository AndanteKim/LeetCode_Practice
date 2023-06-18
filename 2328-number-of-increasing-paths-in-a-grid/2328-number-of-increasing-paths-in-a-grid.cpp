class Solution {
private:
    int m, n, mod = 1'000'000'007;
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if (dp[i][j]) return dp[i][j];
        
        int ans = 1;
        int d[5] = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k){
            int ii = i + d[k], jj = j + d[k + 1];
            if (0 <= ii && ii < m && 0 <= jj && jj < n && grid[ii][jj] < grid[i][j]){
                ans += dfs(ii, jj, dp, grid);
                ans %= mod;
            }
        }
        return dp[i][j] = ans;
    }
    
public:
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                ans = (ans + dfs(i, j, dp, grid)) % mod;
            }
        }
            
        return ans;
    }
};