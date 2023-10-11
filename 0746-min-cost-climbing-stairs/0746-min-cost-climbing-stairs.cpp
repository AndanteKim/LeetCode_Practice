class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), downOne = 0, downTwo = 0;
        
        for (int i = 2; i <= n; ++i){
            int temp = downOne;
            downOne = min(downOne + cost[i - 1], downTwo + cost[i - 2]);
            downTwo = temp;
        }
        
        return downOne;
    }
};