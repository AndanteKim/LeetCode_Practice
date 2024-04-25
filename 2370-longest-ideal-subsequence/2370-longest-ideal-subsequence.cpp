class Solution {
public:
    int longestIdealString(string s, int k) {
        int ans = 0, n = s.size();
        vector<int> dp(26);
        
        // Updating dp with i-th character
        for (int i = 0; i < n; ++i){
            int curr = s[i] - 'a', best = 0;
            for (int prev = 0; prev < 26; ++prev){
                if (abs(curr - prev) <= k)
                    best = max(best, dp[prev]);
            }
            
            // Append s[i] to the previous longest ideal subsequence
            dp[curr] = max(dp[curr], best + 1);
            ans = max(ans, dp[curr]);
        }
        
        return ans;
    }
};