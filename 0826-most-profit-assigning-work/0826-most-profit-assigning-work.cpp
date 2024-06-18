class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobProfile;
        for (int i = 0; i < difficulty.size(); ++i)
            jobProfile.push_back({difficulty[i], profit[i]});
        
        // Sort both jobProfile and worker arrays by increasing order
        sort(jobProfile.begin(), jobProfile.end());
        sort(worker.begin(), worker.end());
        
        int idx = 0, maxProfit = 0, netProfit = 0;
        for (int ability : worker){
            // While the index has not reached the end and worker can pick a job
            // with greater difficulty move ahead.
            while (idx < jobProfile.size() && jobProfile[idx].first <= ability)
                maxProfit = max(maxProfit, jobProfile[idx++].second);
            
            netProfit += maxProfit;
        }
        
        return netProfit;
    }
};