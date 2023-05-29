class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(time + 1, time + 1);
        dp[0] = 0;
        
        for (int i = 1; i <= time && dp[i - 1] < time; ++i){
            for (vector<int>& clip : clips){
                if (i >= clip[0] && i <= clip[1]){
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
                }
            }
        }
        return (dp[time] == time + 1)? -1: dp[time];
    }
};