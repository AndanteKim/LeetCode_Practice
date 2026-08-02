class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector memo(n, vector<int>(n + 1, -1));

        auto dp = [&](auto&& self, int left, int right) -> int {
            if (left == right) return piles[left];

            if (memo[left][right] != -1) return memo[left][right];

            int maxLeft = piles[left] - self(self, left + 1, right);
            int maxRight = piles[right] - self(self, left, right - 1);

            return memo[left][right] = max(maxLeft, maxRight);
        };

        return dp(dp, 0, n - 1);
    }
};