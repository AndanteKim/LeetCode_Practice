class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int d1 = 0, d2 = 0;
        for (int i = 2; i <= cost.size(); ++i){
            int temp = d1;
            d1 = min(cost[i - 1] + d1, cost[i - 2] + d2);
            d2 = temp;
        }
        return d1;
    }
};