class Solution {
private:
    int getDist(int p, int q) {
        int x1 = p / 6, x2 = q / 6;
        int y1 = p % 6, y2 = q % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int minimumDistance(string word) {
        int n = word.size();
        vector dp(n, vector<vector<int>>(26, vector<int>(26, 1 << 30)));
    
        for (int i = 0; i < 26; ++i) {
            dp[0][word[0] - 65][i] = dp[0][i][word[0] - 65] = 0;
        }

        for (int i = 1; i < n; ++i) {
            int prev = word[i - 1] - 65, curr = word[i] - 65;
            int d = getDist(prev, curr);

            for (int j = 0; j < 26; ++j) {
                dp[i][curr][j] = min(dp[i][curr][j], dp[i - 1][prev][j] + d);
                dp[i][j][curr] = min(dp[i][j][curr], dp[i - 1][j][prev] + d);

                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = getDist(curr, k);
                        dp[i][curr][j] = min(dp[i][curr][j], dp[i - 1][k][j] + d0);
                        dp[i][j][curr] = min(dp[i][j][curr], dp[i - 1][j][k] + d0);
                    }
                }
            }
        }

        int ans = 1 << 30;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = min(ans, dp[n - 1][i][j]);
            }
        }

        return ans;
    }
};