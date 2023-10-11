class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minCost(n + 1);
        for (int i = 2; i <= n; ++i){
            int oneStep = minCost[i - 1] + cost[i - 1];
            int twoSteps = minCost[i - 2] + cost[i - 2];
            minCost[i] = min(oneStep, twoSteps);
        }
        
        return minCost.back();
    }
};