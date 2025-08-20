class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0, row = matrix.size(), col = matrix[0].size();
        int prev = 0;
        vector<int> dp(col + 1);

        for (int i = 1; i <= row; ++i){
            for (int j = 1; j <= col; ++j){
                if (matrix[i - 1][j - 1]){
                    int temp = dp[j];
                    dp[j] = min(prev, min(dp[j], dp[j - 1])) + 1;
                    prev = temp;
                    ans += dp[j];
                }
                else dp[j] = 0;
            }
        }

        return ans;
    }
};