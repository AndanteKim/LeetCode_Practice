class Solution {
public:
    int numDecodings(string s) {
        // DP array to store the subproblem results
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        // Ways to decode a string of size 1 is 1. Unless the stirng is '0'.
        // '0' doesn't have a single digit decode
        dp[1] = (s[0] == '0')? 0:1;
        
        for (int i = 2; i <= n; ++i){
            // Check if successful single digit decode is possible.
            if (s[i - 1] != '0')
                dp[i] = dp[i - 1];
            
            // Check if successful two digit decode is possible.
            int twoDigits = stoi(s.substr(i - 2, 2));
            if (twoDigits >= 10 && twoDigits <= 26)
                dp[i] += dp[i - 2];
        }
        
        return dp[n];
    }
};