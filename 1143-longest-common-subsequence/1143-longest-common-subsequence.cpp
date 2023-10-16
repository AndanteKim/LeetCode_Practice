class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector dp(n1 + 1, vector<int>(n2 + 1));
        
        for (int i = n1 - 1; i >= 0; --i){
            for (int j = n2 - 1; j >= 0; --j){
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        
        return dp[0][0];
    }
};