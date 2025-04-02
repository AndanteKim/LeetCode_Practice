class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n);
        dp[n - 1] = questions[n - 1][0];

        for (int i = n - 2; i >= 0; --i){
            int solved = questions[i][0], skip = questions[i][1];
            dp[i] = solved;
            if (i + 1 + skip < n)
                dp[i] += dp[i + 1 + skip];

            // dp[i] = max(solve it, skip it)
            dp[i] = max(dp[i], dp[i + 1]);
        }
        
        return dp[0];
    }
};