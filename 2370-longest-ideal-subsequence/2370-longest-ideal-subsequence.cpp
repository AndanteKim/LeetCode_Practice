class Solution {
private:
    int dfs(int i, int c, vector<vector<int>>& dp, string& s, int k){
        // Memoized value
        if (dp[i][c] != -1) return dp[i][c];
        
        // State is not visited yet
        dp[i][c] = 0;
        bool match = (c == (s[i] - 'a'));
        if (match) dp[i][c] = 1;
        
        // Non base case handling
        if (i > 0){
            dp[i][c] = dfs(i - 1, c, dp, s, k);
            if (match){
                for (int p = 0; p < 26; ++p){
                    if (abs(c - p) <= k)
                        dp[i][c] = max(dp[i][c], dfs(i - 1, p, dp, s, k) + 1);
                }
            }
        }
        
        return dp[i][c];
    }
    
public:
    int longestIdealString(string s, int k) {
        int ans = 0, n = s.size();
        vector<vector<int>> dp(n, vector<int>(26, -1));
        
        // Find the maximum dp[n - 1][c] and return the result
        for (int c = 0; c < 26; ++c)
            ans = max(ans, dfs(n - 1, c, dp, s, k));
        
        return ans;
    }
};