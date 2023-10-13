class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), oneStep = 0, twoSteps = 0;
        
        for (int i = 2; i <= n; ++i){
            int temp = oneStep;
            oneStep = min(oneStep + cost[i - 1], twoSteps + cost[i - 2]);
            twoSteps = temp;
        }
        
        return oneStep;
    }
};