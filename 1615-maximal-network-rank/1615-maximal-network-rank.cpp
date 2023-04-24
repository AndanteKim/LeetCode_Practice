class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> connected;
        for (auto road : roads){
            connected[road[0]].insert(road[1]);
            connected[road[1]].insert(road[0]);
        }
        
        int ans = 0, curr;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                curr = connected[i].size() + connected[j].size()\
                    - (connected[j].find(i) == connected[j].end()? 0 : 1);
                ans = max(ans, curr);
            }
        }
        
        return ans;
    }
};