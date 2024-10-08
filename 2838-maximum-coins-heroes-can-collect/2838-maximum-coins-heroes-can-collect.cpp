class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        int m = coins.size(), n = heroes.size();
        vector<pair<int, int>> monstersAndCoins;
        
        for (int i = 0; i < m; ++i)
            monstersAndCoins.push_back({monsters[i], coins[i]});
        
        // Sort by ascending value of monster power
        sort(monstersAndCoins.begin(), monstersAndCoins.end());
        
        int inf = INT_MAX;
        vector<long long> prefixCoins(m + 1);
        for (int i = 0; i < m; ++i){
            prefixCoins[i + 1] = prefixCoins[i] + monstersAndCoins[i].second;
        }
        
        vector<long long> ans(n);
        for (int i = 0; i < n; ++i){
            pair<int, int> hero = {heroes[i], inf};
            
            int limit = lower_bound(monstersAndCoins.begin(), monstersAndCoins.end(), hero) - monstersAndCoins.begin();
            ans[i] = prefixCoins[limit];
        }
        
        return ans;
    }
};