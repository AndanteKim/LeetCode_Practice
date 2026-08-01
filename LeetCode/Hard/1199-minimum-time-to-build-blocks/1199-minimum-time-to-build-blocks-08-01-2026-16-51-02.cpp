class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        int n = blocks.size();
        vector memo(n, vector<int>(n + 1, -1));
        sort(blocks.begin(), blocks.end(), [](int a, int b) {return a > b;});
        
        auto dp = [&](auto&& self, int b, int w) -> int {
            if (b == n) return 0;

            if (w == 0) return std::numeric_limits<int>::max();

            if (w >= n - b) return blocks[b];

            if (memo[b][w] != -1) return memo[b][w];

            int workHere = max(blocks[b], self(self, b + 1, w - 1));
            int splitHere = split + self(self, b, min(2 * w, n - b));

            return memo[b][w] = min(workHere, splitHere);
        };
        
        return dp(dp, 0, 1);
    }
};