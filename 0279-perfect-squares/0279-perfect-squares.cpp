class Solution {
public:
    int numSquares(int n) {
        vector<int> sqNums, dp(n + 1, 10'001);
        for (int i = 0; i <= (int)sqrt(n); ++i)
            sqNums.push_back(i * i);
        
        dp[0] = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i){
            for (int sq:sqNums){
                if (i < sq)
                    break;
                dp[i] = min(dp[i], dp[i - sq] + 1);
            }
        }
        
        return dp.back();
    }
};