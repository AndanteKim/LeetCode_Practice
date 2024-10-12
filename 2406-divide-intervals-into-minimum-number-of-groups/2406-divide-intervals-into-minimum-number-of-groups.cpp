class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> endedTime;
        int minGroups = 0;
        
        for (const auto& interval : intervals){
            int start = interval[0], end = interval[1];
            while (!endedTime.empty() && endedTime.top() < start)
                endedTime.pop();
            
            endedTime.push(end);
            minGroups = max(minGroups, (int)endedTime.size());
        }
        
        return minGroups;
    }
};