class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowOnes(m), colOnes(n);
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j]){
                    ++rowOnes[i], ++colOnes[j];
                }
            }
        }
        
        vector ans(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                ans[i][j] = 2 * rowOnes[i] + 2 * colOnes[j] - m - n;
            }
        }
        
        return ans;
    }
};