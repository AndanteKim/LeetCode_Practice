class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size(), maxLen = 0;
        vector dp(n + 1, vector<int>(n + 1));
        
        // Populate the DP array
        for (int i = 1; i <= n; ++i){
            for (int j = i + 1; j <= n; ++j){
                // Check if the characters match and update the DP value
                if (s[i - 1] == s[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    
                    // Update the max length
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        
        return maxLen;
    }
};