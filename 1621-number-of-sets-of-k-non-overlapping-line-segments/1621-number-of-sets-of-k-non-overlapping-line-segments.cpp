class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<int> dp(n, 1), prefix(n + 1);
        int MOD = 1'000'000'007;

        for (int i = 0; i < n; ++i) prefix[i + 1] = (prefix[i] + dp[i]) % MOD;

        for (int i = 0; i < k; ++i) {
            dp[0] = 0;
            for (int j = 1; j < n; ++j) dp[j] = (dp[j - 1] + prefix[j]) % MOD;
            for (int j = 0; j < n; ++j) prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
        }

        return dp.back();
    }
};