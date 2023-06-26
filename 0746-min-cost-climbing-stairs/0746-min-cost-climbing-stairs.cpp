class Solution {
private:
    int dp(int i, unordered_map<int, int>& memo, vector<int>& cost){
        if (i <= 1) return 0;
        
        if (memo.find(i) != memo.end()) return memo[i];
        
        return memo[i] = min(cost[i - 1] + dp(i - 1, memo, cost), cost[i - 2] + dp(i - 2, memo, cost));
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> memo;
        
        return dp(cost.size(), memo, cost);
    }
};