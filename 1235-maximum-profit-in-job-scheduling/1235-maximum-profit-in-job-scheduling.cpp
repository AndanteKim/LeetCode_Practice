class Solution {
private:
    // maximum number of jobs are 50000
    int memo[50001];
    int dp(vector<vector<int>>& jobs, vector<int>& start, int n, int pos){
        // 0 profit if we've already iterated over all the jobs
        if (pos == n)
            return 0;
        
        // We've already calculated the answer, so no need to go into recursion
        if (memo[pos] != -1)
            return memo[pos];
        
        // nextIndex is the index of next non-conflicting job
        // lower_bound(binary search) will return the iterator to the first element which is 
        // equal to or greater than the element at 'jobs[pos][1]'
        int nextIndex = lower_bound(start.begin(), start.end(), jobs[pos][1]) - start.begin();
        
        // find the maximum profit of our two options: skipping vs scheduling the current job
        int maxProfit = max(dp(jobs, start, n, pos + 1), jobs[pos][2] + dp(jobs,start, n, nextIndex));
        
        // return the maximum profit and also storing it for future reference(memoization)
        return memo[pos] = maxProfit;
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        // marking all values to -1, so that we can differentiate
        // if we've already calculated the answer or not
        memset(memo, -1, sizeof(memo));
        
        // storing job's details into one list
        // this will help in sorting the jobs while maintaining the other parameters
        int n = profit.size();
        for (int i = 0; i < n; ++i)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        
        // binary search will be used in startTime, so store it as separate list
        for (int i = 0; i < n; ++i)
            startTime[i] = jobs[i][0];
        
        return dp(jobs, startTime, n, 0);
    }
};