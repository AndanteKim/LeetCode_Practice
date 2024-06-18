class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Find maximum ability in the worker array
        int maxAbility = *max_element(worker.begin(), worker.end());
        vector<int> jobs(maxAbility + 1);
        
        for (int i = 0; i < difficulty.size(); ++i)
            if (difficulty[i] <= maxAbility)
                jobs[difficulty[i]] = max(profit[i], jobs[difficulty[i]]);
        
        // Take maxima of prefixes
        for (int i = 1; i < jobs.size(); ++i)
            jobs[i] = max(jobs[i - 1], jobs[i]);
        
        int maxProfit = 0;
        for (int ability : worker){
            maxProfit += jobs[ability];
        }
        
        return maxProfit;
    }
};