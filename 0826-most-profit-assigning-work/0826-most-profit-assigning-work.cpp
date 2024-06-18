class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobProfile{{0, 0}};
        
        for (int i = 0; i < difficulty.size(); ++i)
            jobProfile.push_back({profit[i], difficulty[i]});
        
        // sort in decreasing order of profit
        sort(jobProfile.begin(), jobProfile.end(), [](pair<int, int>& p1, pair<int, int>& p2){return p1.first > p2.first;});
        
        for (int i = 1; i < jobProfile.size(); ++i)
            jobProfile[i] = pair<int, int>{jobProfile[i].first, min(jobProfile[i - 1].second, jobProfile[i].second)};
        
        int netProfit = 0;
        for (int ability : worker){
            int l = 0, r = jobProfile.size() - 1, jobProfit = 0;
            
            // Maximize profit using binary search
            while (l <= r){
                int mid = l + ((r - l) >> 1);
                
                if (jobProfile[mid].second <= ability){
                    r = mid - 1;
                    jobProfit = max(jobProfit, jobProfile[mid].first);
                }
                else l = mid + 1;
            }

            // Add profit of each worker to total profit.
            netProfit += jobProfit;
        }
        
        return netProfit;
    }
};