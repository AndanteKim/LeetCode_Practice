class Solution {
public:
    int numberOfWays(int numPeople) {
        int m = 1'000'000'007;
        vector<int> dp((numPeople >> 1) + 1);
        dp[0] = 1;

        for (int i = 0; i <= (numPeople >> 1); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = (dp[i] + (1LL * dp[j] * dp[i - j - 1])) % m;
            }
        }

        return dp[numPeople >> 1];
    }
};