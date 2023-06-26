class Solution {
private:
    int dp(int i, vector<int>& memo, vector<int>& cost){
        if (i <= 1) return 0;
        
        if (memo[i] != -1) return memo[i];
        
        return memo[i] = min(cost[i - 1] + dp(i - 1, memo, cost), cost[i - 2] + dp(i - 2, memo, cost));
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n + 1, -1);
        
        return dp(cost.size(), memo, cost);
    }
};