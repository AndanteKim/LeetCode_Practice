class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        sort(events.begin(), events.end());
        vector<int> starts(n, 0);
        for (int i = 0; i < n; ++i) starts[i] = events[i][0];
        
        for (int currIndex = n - 1; currIndex >= 0; --currIndex){
            for (int count = 1; count <= k; ++count){
                int nextIndex = upper_bound(starts.begin(), starts.end(), events[currIndex][1]) - starts.begin();
                dp[count][currIndex] = max(dp[count][currIndex + 1], dp[count - 1][nextIndex] + events[currIndex][2]);
            }
        }
        
        return dp[k][0];
    }
};