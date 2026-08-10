class Solution {
public:
    bool winnerSquareGame(int n) {
        unordered_map<int, bool> memo {{0, false}};

        auto dp = [&](auto&& self, int remain) {
            if (memo.contains(remain)) return memo[remain];

            int range = (int)sqrt(remain);
            for (int i = 1; i <= range; ++i) {
                if (!self(self, remain - i * i)) return memo[remain] = true;
            }

            return memo[remain] = false;
        };

       return dp(dp, n);
    }
};