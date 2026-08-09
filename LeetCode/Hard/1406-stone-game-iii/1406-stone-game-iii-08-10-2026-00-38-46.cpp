class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> memo(n, -1);

        auto dp = [&](auto&& self, int i) {
            if (i == n) return 0;

            if (memo[i] != -1) return memo[i];

            int maxDiff = stoneValue[i] - self(self, i + 1);

            if (i < n - 1) {
                maxDiff = max(maxDiff, stoneValue[i] + stoneValue[i + 1] - self(self, i + 2));
            }

            if (i < n - 2) {
                maxDiff = max(maxDiff, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - self(self, i + 3));
            }

            return memo[i] = maxDiff;
        };

        int res = dp(dp, 0);
        return res > 0? "Alice" : res < 0? "Bob" : "Tie";
    }
};