class Solution {
private:
    int dp(int i, vector<int>& cost, vector<int>& memo){
        if (i <= 1)
            return 0;
        if (memo[i] != -1) return memo[i];
        
        int oneStep = cost[i - 1] + dp(i - 1, cost, memo);
        int twoSteps = cost[i - 2] + dp(i - 2, cost, memo);
        return memo[i] = min(oneStep, twoSteps);
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n + 1, -1);
        return dp(n, cost, memo);
    }
};