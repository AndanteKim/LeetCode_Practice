class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        // Base case
        if (m == 1)
            return triangle[0][0];
        
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; ++i){
            dp[i] = vector<int>(triangle[i].size(), 1e5);
        }
        
        dp[0][0] = triangle[0][0];
        for (int i = 0; i < m - 1; ++i){
            for (int j = 0; j < triangle[i].size(); ++j){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
            }
        }
        
        return *min_element(dp.back().begin(), dp.back().end());
    }
};