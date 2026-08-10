class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1);

        for (int i = 0; i <= n; ++i) {
            if (dp[i]) continue;

            for (int k = 1; i + k * k <= n; ++k)
                dp[i + k * k] = true;
            
        }

        return dp[n];
    }
};