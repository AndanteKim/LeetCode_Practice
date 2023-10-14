class Solution {
private:
    int n;
    int dp(int i, int remain, vector<vector<int>>& memo, vector<int>& cost, vector<int>& time){
        if (remain <= 0) return 0;
        if (i == n) return 1e9;
        if (memo[i][remain] != -1) return memo[i][remain];
        
        int paint = cost[i] + dp(i + 1, remain - 1 - time[i], memo, cost, time);
        int dontPaint = dp(i + 1, remain, memo, cost, time);
        return memo[i][remain] = min(paint, dontPaint);
    }
    
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        this -> n = cost.size();
        vector memo(n, vector<int>(n + 1, -1));
        
        return dp(0, n, memo, cost, time);
    }
};