class Solution {
private:
    int n;
    int dp(int i, int prevColor, vector<vector<int>>& costs, vector<vector<int>>& memo){
        if (i == n)
            return 0;
        
        if (prevColor != -1 && memo[i][prevColor] != -1)
            return memo[i][prevColor];
        
        int minCost = INT_MAX;
        for(int colorIdx = 0; colorIdx < 3; ++colorIdx){
            if (colorIdx == prevColor)
                continue;
            minCost = min(minCost, costs[i][colorIdx] + dp(i + 1, colorIdx, costs, memo));
        }
        
        if (prevColor != -1)
            memo[i][prevColor] = minCost;
        return minCost;
    }
    
public:
    int minCost(vector<vector<int>>& costs) {
        this -> n = costs.size();
        vector<vector<int>> memo(n, vector<int>(3, -1));
        return dp(0, -1, costs, memo);
    }
};