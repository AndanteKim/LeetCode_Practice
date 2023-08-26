class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int pos = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        intervals.insert(intervals.begin() + pos, newInterval);
        vector<vector<int>> ans;
        
        for (int i = 0; i < intervals.size(); ++i){
            if (ans.empty() || ans.back()[1] < intervals[i][0]) ans.push_back(intervals[i]);
            else ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        
        return ans;
    }
};