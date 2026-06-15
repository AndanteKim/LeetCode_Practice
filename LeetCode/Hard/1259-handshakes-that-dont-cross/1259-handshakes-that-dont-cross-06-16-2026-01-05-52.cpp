class Solution {
private:
    int m = 1'000'000'007;
    int calculateDp(vector<int>& dp, int i) {
        if (dp[i] != -1) return dp[i];
        dp[i] = 0;

        for (int j = 0; j < i; ++j) {
            dp[i] = (dp[i] + 1LL * calculateDp(dp, j) * calculateDp(dp, i - j - 1)) % m;
        }

        return dp[i];
    }

public:
    int numberOfWays(int numPeople) {
        vector<int> dp((numPeople >> 1) + 1, -1);
        dp[0] = 1;

        return calculateDp(dp, numPeople >> 1);
    }
};