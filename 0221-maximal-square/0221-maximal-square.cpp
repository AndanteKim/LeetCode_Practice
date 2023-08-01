class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0, prev;
        vector<int> dp(n + 1);
        
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1'){
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    ans = max(ans, dp[j]);
                }
                else dp[j] = 0;
                prev = temp;
            }
        }
        
        return ans * ans;
    }
};