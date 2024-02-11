class Solution {
private:
    int m, n;
    int dp(int row, int col1, int col2, vector<vector<vector<int>>>& memo, vector<vector<int>>& grid){
        if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
            return 0;
        // check cache
        if (memo[row][col1][col2] != -1)
            return memo[row][col1][col2];
        
        // Current cell
        int ans = grid[row][col1];
        if (col1 != col2)
            ans += grid[row][col2];
        
        // transition
        if (row != m - 1){
            int mx = 0;
            for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; ++newCol1){
                for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; ++newCol2)
                    mx = max(mx, dp(row + 1, newCol1, newCol2, memo, grid));
            }
            ans += mx;
        }
        memo[row][col1][col2] = ans;
        return ans;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();
        // initial all elements to -1 to mark unseen
        vector memo(m, vector(n, vector<int>(n, -1)));
        return dp(0, 0, n - 1, memo, grid);
    }
};