class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Convert the intervals to two events
        // start as (start, 1) and end as (end + 1, -1)
        vector<pair<int, int>> events;
        
        for (const auto& interval : intervals){
            events.push_back({interval[0], 1});     // Start event
            events.push_back({interval[1] + 1, -1});    // end event (interval[1] + 1);
        }
        
        // Sort the events first by time, and then by type (1 for start. -1 for end)
        sort(events.begin(), events.end(), [](pair<int, int> &a, pair<int, int>& b){
            return (a.first == b.first)? a.second < b.second : a.first < b.first;
        });
        
        int concurrent = 0, maxConcurrent = 0;
        
        // Sweep through the event
        for (auto& [time, check] : events) {
            concurrent += check;    // Track currently active intervals
            maxConcurrent = max(maxConcurrent, concurrent);
        }
        
        return maxConcurrent;
    }
};