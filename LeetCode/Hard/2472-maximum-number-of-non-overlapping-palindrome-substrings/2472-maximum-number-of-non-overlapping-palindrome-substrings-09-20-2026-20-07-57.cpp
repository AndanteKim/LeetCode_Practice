class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector isPal(n, vector<bool>(n, false));

        for (int len = 1; len <= n; ++len) {
            for (int left = 0; left <= n - len; ++left) {
                int right = left + len - 1;
                isPal[left][right] = ((s[left] == s[right]) && (len <= 2 || isPal[left + 1][right - 1]));
            }
        }

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (int j = 0; j <= i - k; ++j) {
                if (isPal[j][i - 1]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return dp[n];
    }
};