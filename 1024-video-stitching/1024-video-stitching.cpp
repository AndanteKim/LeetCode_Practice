class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int end = -1, end2 = 0, ans = 0;
        for (vector<int>& clip : clips){
            if (end2 >= time || clip[0] > end2) break;
            else if (clip[0] > end && clip[0] <= end2){
                ++ans;
                end = end2;
            }
            end2 = max(end2, clip[1]);
        }
        
        return end2 >= time? ans : -1;
    }
};