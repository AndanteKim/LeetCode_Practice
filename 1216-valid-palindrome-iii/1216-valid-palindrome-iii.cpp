class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector dp(n, vector<int>(n));
        
        // Generate all combinations of 'i' and 'j' in the correct order
        for (int i = n - 2; i >= 0; --i){
            for (int j = i + 1; j < n; ++j){
                // Case 1: If character at 'i' equals character at 'j'
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                
                // Case 2: If character at 'i' doesn't equal character at 'j'
                // Either delete characters at 'i' or 'j' and try to match two pointers
                // We need to take the minimum of the two results and add 1 representating the cost of deletion
                else
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[0][n - 1] <= k;
    }
};