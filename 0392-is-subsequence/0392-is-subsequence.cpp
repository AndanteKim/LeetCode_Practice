class Solution {
public:
    bool isSubsequence(string s, string t) {
        int source_len = s.size(), target_len = t.size();
        if (source_len == 0) return true;
        vector<vector<int>> dp(source_len + 1, vector<int>(target_len + 1, 0));
        
        for (int col = 1; col <= target_len; ++col){
            for (int row = 1; row <= source_len; ++row){
                if (s[row-1] == t[col-1]) dp[row][col] = dp[row-1][col-1]+1;
                else dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
            }
            
            if (dp[source_len][col] == source_len) return true;
        }
        
        return false;
    }
};