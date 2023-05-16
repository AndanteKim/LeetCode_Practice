class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        
        for (int house = 1; house < n; ++house){
            for (int color = 0; color < k; ++color){
                int best = INT_MAX;
                for (int prevColor = 0; prevColor < k; ++prevColor){
                    if (color == prevColor) continue;
                    best = min(best, costs[house - 1][prevColor]);
                }
                costs[house][color] += best;
            }
        }
        
        return *min_element(costs.back().begin(), costs.back().end());
    }
};