class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Use a map to store the points and their counts
        map<int, int> pointToCount;
        
        // Mark the starting and ending points in the dictionary
        for (const auto& interval : intervals){
            ++pointToCount[interval[0]];    // Start of an interval
            --pointToCount[interval[1] + 1];    // End of an interval (interval[1] + 1)
        }
        
        int concurrent = 0, maxConcurrent = 0;
        
        // Iterate over the sorted keys of the dictionary
        for (const auto& [time, count] : pointToCount){
            concurrent += count;    // Update currently active intervals
            maxConcurrent = max(maxConcurrent, concurrent); // Update max intervals
        }
        
        return maxConcurrent;
    }
};