class Solution {
private:
    int dp(int row, int col, vector<vector<int>>& memo){
        if (row + col == 0) return 1;
        
        if (memo[row][col] != -1) return memo[row][col];
        
        int ways = 0;
        if (row > 0) ways += dp(row - 1, col, memo);
        if (col > 0) ways += dp(row, col - 1, memo);
        
        return memo[row][col] = ways;
    }
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        return dp(m - 1, n - 1, memo);
    }
};