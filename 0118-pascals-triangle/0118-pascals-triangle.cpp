class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 2) return numRows == 1? vector<vector<int>>{{1}} : vector<vector<int>>{{1}, {1, 1}};
        vector<vector<int>> dp{{{1}, {1, 1}}};
        for (int i = 3; i < numRows + 1; ++i){
            vector<int> curr(i, 1);
            for (int j = 1; j < i - 1; ++j){
                curr[j] = dp[i - 2][j - 1] + dp[i - 2][j];
            }
            dp.push_back(curr);
        }
        
        return dp;
    }
};