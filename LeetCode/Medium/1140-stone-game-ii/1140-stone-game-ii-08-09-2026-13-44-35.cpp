class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(piles.begin(), piles.end());

        for (int i = n - 2; i >= 0; --i) suffix[i] += suffix[i + 1];

        vector memo(n, vector<int>(n, -1));

        auto dp = [&](auto&& self, int i, int M) {
            // Base case
            if (i + 2 * M >= n) return suffix[i];

            if (memo[i][M] != -1) return memo[i][M];

            int ans = std::numeric_limits<int>::max();
            for (int X = 1; X <= 2 * M; ++X) {
                ans = min(ans, self(self, i + X, max(X, M)));
            }

            return memo[i][M] = suffix[i] - ans; 
        };

        return dp(dp, 0, 1);
    }
};