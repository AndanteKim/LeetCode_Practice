class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> pq;
        vector<string> ans(n), awards;
        
        for (int i = 0; i < n; ++i){
            pq.push({score[i], i});
            if (i == 0)
                awards.push_back("Gold Medal");
            else if (i == 1)
                awards.push_back("Silver Medal");
            else if (i == 2)
                awards.push_back("Bronze Medal");
            else awards.push_back(to_string(i + 1));
        }
        
        int curr = 0;
        while (!pq.empty()){
            auto [rank, idx] = pq.top(); pq.pop();
            ans[idx] = awards[curr++];
        }
        
        return ans;
    }
};