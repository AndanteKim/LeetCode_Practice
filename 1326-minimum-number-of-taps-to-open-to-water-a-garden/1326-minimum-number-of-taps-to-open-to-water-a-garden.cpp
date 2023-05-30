class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        
        for (int startLine = 0; startLine < ranges.size(); ++startLine){
            for (int i = max(startLine - ranges[startLine] + 1, 0); i <= min(startLine + ranges[startLine], n); ++i){
                dp[i] = min(dp[i], dp[max(0, startLine - ranges[startLine])] + 1);
            }
        }
        
        return dp.back() == n + 1? -1 : dp.back();
    }
};