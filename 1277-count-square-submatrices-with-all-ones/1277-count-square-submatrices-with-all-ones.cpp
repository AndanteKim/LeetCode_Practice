class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector dp(row + 1, vector<int>(col + 1));
        int ans = 0;

        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (matrix[i][j]) {
                    dp[i + 1][j + 1] = min(\
                    dp[i + 1][j], min(dp[i][j + 1],\
                    dp[i][j])) + 1;
                    ans += dp[i + 1][j + 1];
                }
            }
        }

        return ans;
    }
};