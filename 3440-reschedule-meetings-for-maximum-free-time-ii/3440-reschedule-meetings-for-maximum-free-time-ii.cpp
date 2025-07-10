class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), ans = 0, t1 = 0, t2 = 0;
        vector<int> q(n);

        for (int i = 0; i < n; ++i) {
            if (endTime[i] - startTime[i] <= t1)
                q[i] = true;
            t1 = max(t1, startTime[i] - (i == 0? 0 : endTime[i - 1]));

            if (endTime[n - 1 - i] - startTime[n - 1 - i] <= t2)
                q[n - 1 - i] = true;
            t2 = max(t2, (i == 0? eventTime : startTime[n - i]) - endTime[n - 1 - i]);
        }

        for (int i = 0; i < n; ++i){
            int right = i == n - 1? eventTime : startTime[i + 1];
            int left = i == 0? 0 : endTime[i - 1];
            
            if (q[i])
                ans = max(ans, right - left);
            else
                ans = max(ans, right - left - (endTime[i] - startTime[i]));
        }

        return ans;
    }
};