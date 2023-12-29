class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        
        // Initialize maxDiffNextDay matrix to record the minimum difficulty of the job schedule
        vector<int> minDiffNextDay(n + 1, INT_MAX);
        minDiffNextDay.back() = 0;
        
        for (int daysRemaining = 1; daysRemaining <= d; ++daysRemaining){
            // Initialize maxCurrNextDay matrix to record the minimum difficulty of the job schedule
            vector<int> minDiffCurrDay(n + 1, INT_MAX);
            minDiffCurrDay.back() = 0;
            for (int i = 0; i <= n - daysRemaining; ++i){
                int dailyMaxJobDiff = 0;
                for (int j = i + 1; j <= n - daysRemaining + 1; ++j){
                    // Use dailyMaxJobDiff to record maximum job difficulty
                    dailyMaxJobDiff = max(dailyMaxJobDiff, jobDifficulty[j - 1]);
                    if (minDiffNextDay[j] != INT_MAX)
                        minDiffCurrDay[i] = min(minDiffCurrDay[i], dailyMaxJobDiff + minDiffNextDay[j]);
                }
            }
            minDiffNextDay = minDiffCurrDay;
        }
        
        return (minDiffNextDay[0] == INT_MAX)? -1: minDiffNextDay[0];
    }
};