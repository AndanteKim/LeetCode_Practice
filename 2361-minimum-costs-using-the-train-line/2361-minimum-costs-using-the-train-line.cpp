typedef long long ll;

class Solution {
private:
    ll solve(int i, int lane, vector<vector<ll>>& dp, vector<int>& regular, vector<int>& express, int expressCost){
        if (i < 0) return 0;
        if (dp[i][lane] != -1) return dp[i][lane];
        
        ll regularLane = regular[i] + solve(i - 1, 1, dp, regular, express, expressCost);
        ll expressLane = (lane? expressCost: 0) + express[i] + solve(i - 1, 0, dp, regular, express, expressCost);
        dp[i][lane] = min(regularLane, expressLane);
        return dp[i][lane];
    }
        
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size(); 
        vector<vector<ll>> dp(n, vector<ll>(2, -1));
        vector<ll> ans;
        solve(n - 1, 1, dp, regular, express, expressCost);
        for (int i = 0; i < n; ++i)
            ans.push_back(dp[i][1]);
        
        return ans;
    }
};