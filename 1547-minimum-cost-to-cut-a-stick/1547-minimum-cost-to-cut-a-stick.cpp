class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));
        
        for (int diff = 2; diff <= m + 1; ++diff){
            for (int left = 0; left <= m + 1 - diff; ++left){
                int right = left + diff, ans = INT_MAX;
                
                for (int mid = left + 1; mid < right; ++mid)
                    ans = min(ans, dp[left][mid] + dp[mid][right] + cuts[right] - cuts[left]);
                
                dp[left][right] = ans;
            }
        }
        
        return dp[0][m + 1];
    }
};