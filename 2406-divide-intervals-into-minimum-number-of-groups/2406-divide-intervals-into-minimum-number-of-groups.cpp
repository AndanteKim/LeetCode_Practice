class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Find the minimum and maximum value in the interval
        int rangeStart = INT_MAX, rangeEnd = INT_MIN;
        for (const auto& interval : intervals){
            rangeStart = min(rangeStart, interval[0]);
            rangeEnd = max(rangeEnd, interval[1]);
        }
        
        // Initialize the list with all zeroes
        vector<int> pointToCount(rangeEnd + 2);
        for (const auto& interval : intervals){
            ++pointToCount[interval[0]];
            --pointToCount[interval[1] + 1];
        }
        
        int concurrent = 0, maxConcurrent = 0;
        for (int i = rangeStart; i <= rangeEnd; ++i){
            // Update currently active intervals
            concurrent += pointToCount[i];
            maxConcurrent = max(maxConcurrent, concurrent);
        }
        
        return maxConcurrent;
    }
};