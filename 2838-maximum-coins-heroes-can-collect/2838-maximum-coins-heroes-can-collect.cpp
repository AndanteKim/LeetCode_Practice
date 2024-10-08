class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        int m = coins.size(), n = heroes.size();
        vector<pair<int, int>> pairs;
        
        for (int i = 0; i < m; ++i)
            pairs.push_back({monsters[i], coins[i]});
        
        sort(pairs.begin(), pairs.end());
        
        int inf = INT_MAX;
        vector<long long> prefixCoins(m + 1);
        for (int i = 0; i < m; ++i){
            prefixCoins[i + 1] = prefixCoins[i] + pairs[i].second;
        }
        
        vector<long long> ans(n);
        for (int i = 0; i < n; ++i){
            pair<int, int> hero = {heroes[i], inf};
            
            int limit = lower_bound(pairs.begin(), pairs.end(), hero) - pairs.begin();
            ans[i] = prefixCoins[limit];
        }
        
        return ans;
    }
};