class Solution {
private:
    int n;
    
    int findMaxProfit(vector<vector<int>>& jobs, vector<int>& startTime){
        vector<int> dp(50001);
        
        for (int pos = n - 1; pos >= 0; --pos){
            // It's the profit made by scheduling the current job
            int currProfit = 0;
            
            // nextIndex is the index of non-conflicting job
            // lower_bound will return the iterator to the first element which is equal to or
            // greater than the element 'jobs[pos][1]'
            int nextIndex = lower_bound(startTime.begin(), startTime.end(), jobs[pos][1]) - startTime.begin();
            
            // If there is a non-conflicting job possible add it's profit
            // else just consider the current job profit
            if (nextIndex != n)
                currProfit = jobs[pos][2] + dp[nextIndex];
            else
                currProfit = jobs[pos][2];
            
            // Storing the maximum profit we can achieve by scheduling
            // non-conflicting jobs from index i to the end of array
            if (pos == n - 1)
                dp[pos] = currProfit;
            else
                dp[pos] = max(currProfit, dp[pos + 1]);
        }
        
        return dp[0];
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        this -> n = profit.size();
        
        // storing job's details into one list
        // this will help in sorting the jobs while maintaining the other parameters
        for (int i = 0; i < n; ++i)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
      
        sort(jobs.begin(), jobs.end());
        
        // binary search will be used in startTinme, so store it as separate list
        for (int i = 0; i < n; ++i)
            startTime[i] = jobs[i][0];
        
        return findMaxProfit(jobs, startTime);
    }
};