class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Create a bucket array for the times converted to minutes
        vector<bool> minutes(24 * 60, false);
        
        for (const auto& time : timePoints){
            int h = stoi(time.substr(0, 2)), m = stoi(time.substr(3));
            int minTime = 60 * h + m;
            
            if (minutes[minTime])
                return 0;
            
            minutes[minTime] = true;
        }
            
        int prevIndex = INT_MAX, firstIndex = INT_MAX;
        int lastIndex = INT_MAX, ans = INT_MAX;
        
        // Find differences between adjacent elements in sorted array
        for (int i = 0; i < 24 * 60; ++i){
            if (minutes[i]){
                if (prevIndex != INT_MAX)
                    ans = min(ans, i - prevIndex);
                
                prevIndex = i;
                if (firstIndex == INT_MAX)
                    firstIndex = i;
                lastIndex = i;
            }
        }
        
        return min(ans, 60 * 24 - lastIndex + firstIndex);
    }
};