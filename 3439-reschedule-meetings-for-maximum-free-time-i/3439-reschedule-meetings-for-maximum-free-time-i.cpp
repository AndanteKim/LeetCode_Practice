class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), ans = 0, t = 0;

        for (int i = 0; i < n; ++i){
            t += endTime[i] - startTime[i];
            int right = i == n - 1? eventTime : startTime[i + 1];
            int left = i <= k - 1? 0 : endTime[i - k];
            
            ans = max(ans, right - left - t);
            if (i >= k - 1) t -= endTime[i - k + 1] - startTime[i - k + 1];
        }

        return ans;
    }
};