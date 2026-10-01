typedef long long ll;

class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();

        vector dp(n + 1, vector<ll>(2));
        dp[0][0] = expressCost, dp[0][1] = 0;
        vector<ll> ans;

        for (int i = 1; i <= n; ++i) {
            // [i][0] := express lane, [i][1] := regular lane
            dp[i][0] = express[i - 1] + min(dp[i - 1][0], expressCost + dp[i - 1][1]);
            dp[i][1] = regular[i - 1] + min(dp[i - 1][0], dp[i - 1][1]);

            ans.push_back(min(dp[i][0], dp[i][1]));
        }

        return ans;
    }
};