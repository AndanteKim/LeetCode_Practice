class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> targetTime = times[targetFriend];
        sort(times.begin(), times.end());
        int n = times.size();
        vector<int> chairsTime(n);
        
        for (vector<int>& time : times){
            for (int i = 0; i < n; ++i){
                if (chairsTime[i] <= time[0]){
                    chairsTime[i] = time[1];
                    if (time == targetTime)
                        return i;
                    break;
                }
            }
        }
        
        return 0;
    }
};