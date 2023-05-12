class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return true;
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); ++i){
            if (prev[1] > intervals[i][0]) return false;
            prev = intervals[i];
        }
        return true;
    }
};