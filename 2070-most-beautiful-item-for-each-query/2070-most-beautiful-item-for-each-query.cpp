class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> reducedItems;
        for (const auto& item : items){
            reducedItems[item[0]] = max(reducedItems[item[0]], item[1]);
        }
        
        vector<pair<int, int>> maxItems;
        int maxBeauty = 0;
        for (const auto& [price, beauty] : reducedItems){
            maxItems.push_back({price, max(maxBeauty, beauty)});
            maxBeauty = max(maxBeauty, beauty);
        }
        sort(maxItems.begin(), maxItems.end());
        
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i){
            if (queries[i] < maxItems[0].first)
                continue;
            
            int maxItemsIndex = upper_bound(maxItems.begin(), maxItems.end(), make_pair(queries[i], INT_MAX)) - maxItems.begin();
            ans[i] = maxItems[maxItemsIndex - 1].second;
        }
        
        return ans;
    }
};