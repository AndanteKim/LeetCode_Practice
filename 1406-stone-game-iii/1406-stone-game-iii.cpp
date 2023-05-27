class Solution {
    int n, notComputed;
    int f(int i, vector<int>& dp, vector<int>& stoneValue){
        if (i == n) return 0;
        if (dp[i] != notComputed) return dp[i];
        dp[i] = stoneValue[i] - f(i + 1, dp, stoneValue);
        if (i + 2 <= n)
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - f(i + 2, dp, stoneValue));
        if (i + 3 <= n)
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - f(i + 3, dp, stoneValue));
        return dp[i];
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size(), notComputed = pow(10, 9);
        vector<int> dp(n + 1, notComputed);
        int dif = f(0, dp, stoneValue);
        if (dif > 0) return "Alice";
        if (dif < 0) return "Bob";
        return "Tie";
    }
};