class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int maxEnd = n;
        vector<pair<int, int>> intervals;
        
        for (int i = 0; i < ranges.size(); ++i){
            intervals.push_back(make_pair(max(0, i - ranges[i]), min(n, i + ranges[i])));
        }
        sort(intervals.begin(), intervals.end());
        
        
        int N = intervals.size(), currentEnd = 0, maxReachableEnd = 0, i = 0, count = 0;
        while (currentEnd < maxEnd){
            while (i < N && intervals[i].first <= currentEnd){
                maxReachableEnd = max(maxReachableEnd, intervals[i].second);
                ++i;
            }
            
            if (currentEnd == maxReachableEnd) return -1;
            currentEnd = maxReachableEnd;
            ++count;
        }
        
        return count;
    }
};