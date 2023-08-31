class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // create a list to track the maximum reach for each position
        vector<int> maxReach(n + 1, 0);
        
        // calculate the maximum reach for each tap
        for (int i = 0; i < ranges.size(); ++i){
            // calculate the leftmost and rightmost position, so that each tap can be reached
            int start = max(0, i - ranges[i]), end = min(n, i + ranges[i]);
            // update the maximum reach for the leftmost position
            maxReach[start] = max(maxReach[start], end);
        }
        
        // number of taps used
        int taps = 0;
        // current rightmost position reached
        int currEnd = 0;
        // next rightmost position that can be reached
        int nextEnd = 0;
        // Iterate through the garden
        for (int i = 0; i <= n; ++i){
            if (i > nextEnd) return -1;
            if (i > currEnd){
                // increment taps when moving to a new tap
                ++taps;
                // move to the rightmost position
                currEnd = nextEnd;
            }
            // Update the next rightmost position can be reached
            nextEnd = max(nextEnd, maxReach[i]);
        }
        
        return taps;
    }
};