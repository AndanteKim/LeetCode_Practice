class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Convert input to minutes
        vector<int> minutes;
        
        for (const auto& time : timePoints){
            int h = stoi(time.substr(0, 2)), m = stoi(time.substr(3));
            minutes.push_back(60 * h + m);
        }
        
        // Sort times in ascending order
        sort(minutes.begin(), minutes.end());
        int n = minutes.size(), ans = INT_MAX;
        
        // Find the minimum difference across adjacent elements
        for (int i = 0; i < n - 1; ++i)
            ans = min(ans, minutes[i + 1] - minutes[i]);
        
        // Consider difference between the last and first element
        return min(ans, 60 * 24 - minutes.back() + minutes[0]);
    }
};