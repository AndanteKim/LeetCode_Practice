class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = std::numeric_limits<int>::max(), m = landStartTime.size(), n = waterStartTime.size();

        for (int i = 0; i < m; ++i) {
            int elapsed = landStartTime[i] + landDuration[i];
            for (int j = 0; j < n; ++j) {
                int curr = max(elapsed, waterStartTime[j]) + waterDuration[j];
                ans = min(ans, curr);
            }
        }

        for (int j = 0; j < n; ++j) {
            int elapsed = waterStartTime[j] + waterDuration[j];
            for (int i = 0; i < m; ++i) {
                int curr = max(elapsed, landStartTime[i]) + landDuration[i];
                ans = min(ans, curr);
            }
        }

        return ans;
    }
};