class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int position = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        intervals.insert(intervals.begin() + position, newInterval);
        vector<vector<int>> answer;
        
        for (int i = 0; i < intervals.size(); ++i){
            if (answer.empty() || answer.back()[1] < intervals[i][0]) answer.push_back(intervals[i]);
            else answer.back()[1] = max(answer.back()[1], intervals[i][1]);
        }
        return answer;
    }
};