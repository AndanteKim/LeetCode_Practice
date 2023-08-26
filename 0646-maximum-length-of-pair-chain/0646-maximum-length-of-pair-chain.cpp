class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(), ans = 1;
        vector<int> dp(n, 1);
        sort(pairs.begin(), pairs.end());
        
        for (int i = n - 1; i >= 0; --i){
            for (int j = i + 1; j < n; ++j){
                if (pairs[i][1] < pairs[j][0]) dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};