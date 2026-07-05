using Pll = pair<int, int>;

class Solution {
private:
    static constexpr int MOD = 1'000'000'007;
    int n;
    void update(vector<vector<Pll>>& dp, int x, int y, int u, int v) {
        if (u >= n || v >= n || dp[u][v].first == -1)
            return;

        if (dp[u][v].first > dp[x][y].first)
            dp[x][y] = dp[u][v];
        else if (dp[u][v].first == dp[x][y].first) {
            dp[x][y].second =
                ((long long)dp[x][y].second + dp[u][v].second) % MOD;
        }
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        this->n = board.size();
        vector dp(n, vector<Pll>(n, {-1, 0}));
        dp.back().back() = {0, 1};

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (!(i == n - 1 && j == n - 1) && board[i][j] != 'X') {
                    update(dp, i, j, i + 1, j);
                    update(dp, i, j, i, j + 1);
                    update(dp, i, j, i + 1, j + 1);

                    if (dp[i][j].first != -1) {
                        dp[i][j].first += (
                            board[i][j] == 'E'? 0 : board[i][j] - '0'
                        );
                    }
                }
            }
        }

        return dp[0][0].first == -1? vector<int>{0, 0} : vector<int>{dp[0][0].first, dp[0][0].second};
    }
};