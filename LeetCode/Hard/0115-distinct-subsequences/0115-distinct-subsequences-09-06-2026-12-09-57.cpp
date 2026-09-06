class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<unsigned int> dp(n + 1);

        for (int i = m - 1; i >= 0; --i) {
            unsigned int prev = 1;

            for (int j = n - 1; j >= 0; --j) {
                unsigned int oldDp = dp[j];
                if (s[i] == t[j]) dp[j] += prev;

                prev = oldDp;
            }
        }

        return dp[0];
    }
};