typedef long long ll;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> numAndCost;
        for (int i = 0; i < n; ++i){
            numAndCost.push_back({nums[i], cost[i]});
        }
        
        sort(numAndCost.begin(), numAndCost.end());
        vector<ll> prefixCost(n, 0);
        prefixCost[0] = numAndCost[0].second;
        for (int i = 1; i < n; ++i) prefixCost[i] = prefixCost[i - 1] + numAndCost[i].second;
        
        ll totalCost = 0;
        for (int i = 1; i < n; ++i){
            totalCost += (ll) numAndCost[i].second * (numAndCost[i].first - numAndCost[0].first);
        }
        
        ll ans = totalCost;
        for (int i = 1; i < n; ++i){
            ll gap = numAndCost[i].first - numAndCost[i - 1].first;
            totalCost += prefixCost[i - 1] * gap;
            totalCost -= gap * (prefixCost[n - 1] - prefixCost[i - 1]);
            ans = min(ans, totalCost);
        }
        return ans;
    }
};