class Solution {
private:
    int n;
    int minDiff(int i, int remain, vector<vector<int>>& memo, vector<int>& maxJobRemaining, vector<int>& jobDifficulty){
        // base case: Finish all remaining jobs in the last day
        if (remain == 1)
            return maxJobRemaining[i];
        
        // top down memoization
        if (memo[i][remain] != -1)
            return memo[i][remain];
        
        // keep track of the maximum difficulty for today
        int ans = INT_MAX, dailyMaxJobDiff = 0;
        
        // Iterate through possible starting index for the next day and ensure we have at least one job
        // for each remaining day
        for (int j = i; j <= n - remain; ++j){
            dailyMaxJobDiff = max(dailyMaxJobDiff, jobDifficulty[j]);
            ans = min(ans, dailyMaxJobDiff + minDiff(j + 1, remain - 1, memo, maxJobRemaining, jobDifficulty));
        }
        
        return memo[i][remain] = ans;
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this -> n = jobDifficulty.size();
        
        // edge cases: make sure there is at least 1 job per day
        if (n < d)
            return -1;
        
        vector memo(n + 1, vector<int>(d + 1, -1));
        // precompute the max job difficulty for remaining jobs
        vector<int> maxJobRemaining = jobDifficulty;
        for (int i = n - 2; i >= 0; --i)
            maxJobRemaining[i] = max(maxJobRemaining[i], maxJobRemaining[i + 1]);
        
        return minDiff(0, d, memo, maxJobRemaining, jobDifficulty);
    }
};