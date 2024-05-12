class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int> (n - 2));
        
        for (int i = 1; i <= n - 2; ++i){
            for (int j = 1; j <= n - 2; ++j){
                ans[i - 1][j - 1] = grid[i][j];
                for (auto& [r, c] : vector<pair<int, int>>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1},\
                     {i - 1, j - 1}, {i - 1, j + 1}, {i + 1, j + 1}, {i + 1, j - 1}})
                    ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[r][c]);
            }
        }
        
        return ans;
    }
};