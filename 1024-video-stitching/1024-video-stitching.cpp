class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        vector<int> dp(101, 101);
        dp[0] = 0;
        for (vector<int>& clip : clips){
            for (int i = clip[0] + 1; i <= clip[1]; ++i){
                dp[i] = min(dp[i], dp[clip[0]] + 1);
            }
        }
        return (dp[time] >= 100)? -1: dp[time];
    }
};