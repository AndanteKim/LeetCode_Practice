class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector dp(n, vector<bool>(n));
        pair<int, int> ans;
        
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        
        for (int i = 0; i < n - 1; ++i){
            if (s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                ans.first = i, ans.second = i + 1;
            }
        }
        
        for (int diff = 2; diff < n; ++diff){
            for (int i = 0; i < n - diff; ++i){
                int j = i + diff;
                
                // match middle bridge
                if (s[i] == s[j] && dp[i + 1][j - 1]){
                    ans.first = i;
                    ans.second = j;
                    dp[i][j] = true;
                }
            }
        }
        
        return s.substr(ans.first, ans.second - ans.first + 1);
    }
};