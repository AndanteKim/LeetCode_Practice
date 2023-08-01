typedef long long ll;

class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();
        vector dp(n + 1, vector<ll>(2));
        vector<ll> ans;
        dp[0][1] = 0;
        dp[0][0] = expressCost;
        
        // 1: regular lane, 0: express lane
        for (int i = 1; i <= n; ++i){
            dp[i][1] = regular[i - 1] + min(dp[i - 1][1], dp[i - 1][0]);
            dp[i][0] = express[i - 1] + min(dp[i - 1][0], dp[i - 1][1] + expressCost);
            ans.push_back(min(dp[i][1], dp[i][0]));
        }
        
        return ans;
    }
};