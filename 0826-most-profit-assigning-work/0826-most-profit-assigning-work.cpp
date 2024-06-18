class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobProfile{{0, 0}};
        
        for (int i = 0; i < difficulty.size(); ++i) jobProfile.push_back({difficulty[i], profit[i]});
        
        // sort by difficulty in increasing order.
        sort(jobProfile.begin(), jobProfile.end());
        for (int i = 1; i < jobProfile.size(); ++i)
            jobProfile[i] = pair<int, int>{jobProfile[i].first, max(jobProfile[i - 1].second, jobProfile[i].second)};
        
        int netProfit = 0;
        for (int ability : worker){
            // Find the job with just smaller or equal difficulty than ability.
            int left = 0, right = jobProfile.size() - 1, profit = 0;
            while (left <= right){
                int mid = left + ((right - left) >> 1);
                
                if (jobProfile[mid].first <= ability){
                    profit = max(profit, jobProfile[mid].second);
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            
            // Increment profit of current worker to total profit
            netProfit += profit;
        }
        
        return netProfit;
    }
};