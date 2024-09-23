class Solution {
private:
    int m;
    int dp(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& memo){
        if (memo[row][col] != -1)
            return memo[row][col];
        
        int path = triangle[row][col];
        if (row < m - 1)
            path += min(dp(row + 1, col, triangle, memo), dp(row + 1, col + 1, triangle, memo));
        
        return memo[row][col] = path;
    }
    
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        this -> m = triangle.size();
        vector<vector<int>> memo(m);
        for (int i = 0; i < m; ++i) memo[i] = vector<int>(triangle[i].size(), -1);
        
        // Top down DP
        return dp(0, 0, triangle, memo);
    }
};