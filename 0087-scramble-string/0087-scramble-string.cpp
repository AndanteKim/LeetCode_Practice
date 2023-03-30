class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector dp(n+1, vector(n, vector<int>(n, 0)));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j)
                dp[1][i][j] = s1[i] == s2[j];
        }
        
        for (int length = 2; length < n + 1; ++length){
            for (int i = 0; i < n + 1 - length; ++i){
                for (int j = 0; j < n + 1 - length; ++j){
                    for (int new_length = 1; new_length < length; ++new_length){
                        const vector<int>& dp1 = dp[new_length][i], &dp2 = dp[length - new_length][i + new_length];
                        dp[length][i][j] |= dp1[j] && dp2[j + new_length];
                        dp[length][i][j] |= dp1[j + length - new_length] && dp2[j];
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};