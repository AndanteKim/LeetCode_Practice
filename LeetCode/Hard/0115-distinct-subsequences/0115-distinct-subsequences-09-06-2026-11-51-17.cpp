class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector memo(m, vector<int>(n, -1));

        auto dp = [&](auto&& self, int i, int j) {
            // Base case
            if (j == n) return 1;
            if (i == m) return 0;

            if (memo[i][j] != -1) return memo[i][j];

            int total = 0;
            
            if (s[i] == t[j]) total += self(self, i + 1, j + 1);
            total += self(self, i + 1, j);

            return memo[i][j] = total;
        };


        return dp(dp, 0, 0);
    }
};