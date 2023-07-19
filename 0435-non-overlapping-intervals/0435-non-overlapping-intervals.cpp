class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2){return i1[1] < i2[1];});
        
        int k = INT_MIN, ans = 0;
        for (vector<int>& interval : intervals){
            if (interval[0] >= k) k = interval[1];
            else ++ans;
        }
        
        return ans;
    }
};