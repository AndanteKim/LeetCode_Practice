class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int usedRooms = 0;
        vector<int> startTime, endTime;
        for (int i = 0; i < intervals.size(); ++i){
            startTime.push_back(intervals[i][0]);
            endTime.push_back(intervals[i][1]);
        }
        
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int n = intervals.size(), startPtr = 0, endPtr = 0;
        
        while (startPtr < n){
            if (startTime[startPtr] >= endTime[endPtr]) {
                --usedRooms;
                ++endPtr;
            }
            ++usedRooms;
            ++startPtr;
        }
        
        return usedRooms;
    }
};