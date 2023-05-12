#define ll long long

class Solution {
    int n;
    ll dfs(int i, vector<ll>& dp, vector<vector<int>>& questions){
        if (i >= n) return 0;
        if (dp[i]) return dp[i];
        
        int pts = questions[i][0], skip = questions[i][1];
        dp[i] = max(dfs(i + 1, dp, questions), pts + dfs(i + skip + 1, dp, questions));
        return dp[i];
    }
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        vector<ll> dp(n, 0);
        return dfs(0, dp, questions);
    }
};