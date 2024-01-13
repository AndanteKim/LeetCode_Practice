class Solution {
private:
    int n;
    int findMaxProfit(vector<vector<int>>& jobs){
        // min heap haaving {endTime, profit}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int maxProfit = 0;
        
        for (int i = 0; i < n; ++i){
            int start = jobs[i][0], end = jobs[i][1], profit = jobs[i][2];
            
            // keep popping while the heap is not empty and
            // jobs are not conflicting
            // update the value of maxProfit
            while (!pq.empty() && start >= pq.top().first){
                maxProfit = max(maxProfit, pq.top().second);
                pq.pop();
            }
            
            // push the job with combined profit
            // if no non-conflicting job is present maxProfit will be 0
            pq.push({end, profit + maxProfit});
        }
        
        // Update the value of maxProfit by comparing with
        // profit of jobs that exists in the heap
        while(!pq.empty()){
            maxProfit = max(maxProfit, pq.top().second);
            pq.pop();
        }
        
        return maxProfit;
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        this -> n = profit.size();
        vector<vector<int>> jobs;
        
        // storing job's details into one list
        // this will help in sorting the jobs while maintaining the other parameters
        for (int i = 0; i < profit.size(); ++i)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        return findMaxProfit(jobs);
    }
};