class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;
        
        // Initialize the minDiff matrix to record the minimum difficulty of the job schedule
        vector minDiff(d + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i <= d; ++i)
            minDiff[i].back() = 0;
        
        for (int daysRemaining = 1; daysRemaining <= d; ++daysRemaining){
            for (int i = 0; i <= n - daysRemaining; ++i){
                int dailyMaxJobDiff = 0;
                for (int j = i + 1; j <= n - daysRemaining + 1; ++j){
                    // Use dailyMaxJobDiff to record maximum job difficulty
                    dailyMaxJobDiff = max(dailyMaxJobDiff, jobDifficulty[j - 1]);
                    if (minDiff[daysRemaining - 1][j] != INT_MAX)
                        minDiff[daysRemaining][i] = min(minDiff[daysRemaining][i], dailyMaxJobDiff + minDiff[daysRemaining - 1][j]);
                }
            }
        }
        
        return (minDiff[d][0] == INT_MAX)? -1: minDiff[d][0];
    }
};