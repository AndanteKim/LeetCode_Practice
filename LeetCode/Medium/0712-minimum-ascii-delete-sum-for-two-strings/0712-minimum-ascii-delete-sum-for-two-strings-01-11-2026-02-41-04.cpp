class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> prevDp(n + 1), dp(n + 1);

        for (int j = 1; j <= n; ++j)
            prevDp[j] = prevDp[j - 1] + s2[j - 1];

        
        for (int i = 1; i <= m; ++i) {
            dp[0] = prevDp[0] + s1[i - 1];
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[j] = prevDp[j - 1];
                else {
                    dp[j] = min(
                        dp[j - 1] + s2[j - 1],
                        prevDp[j] + s1[i - 1]
                    );
                }
            }
            prevDp = dp;
        }
        
        return prevDp[n];
    }
};