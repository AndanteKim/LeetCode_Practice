class Solution {
private:
    int dp(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo){
        if (i >= 0 && j >= 0 && obstacleGrid[i][j]) return 0;
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        return memo[i][j] = dp(i - 1, j, obstacleGrid, memo) + dp(i, j - 1, obstacleGrid, memo);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        return dp(m - 1, n - 1, obstacleGrid, memo);
    }
};