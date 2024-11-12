class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // sort both items and queries in ascending order
        sort(items.begin(), items.end());
        vector<pair<int, int>> queriesWithIndex;
        for (int i = 0; i < queries.size(); ++i)
            queriesWithIndex.push_back({queries[i], i});
        
        sort(queriesWithIndex.begin(), queriesWithIndex.end());
        int n = items.size(), itemIndex = 0, maxBeauty = 0;
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i){
            auto [query, originalIndex] = queriesWithIndex[i];
            
            while (itemIndex < n && items[itemIndex][0] <= query){
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                ++itemIndex;
            }
            ans[originalIndex] = maxBeauty;
        }
        
        return ans;
    }
};