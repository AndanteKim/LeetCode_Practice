class Solution {
public:
    int maxA(int n) {
        vector<int> dp;
        for (int i = 0; i <= n + 1; ++i) dp.push_back(i);
        
        for (int i = 0; i <= n - 3; ++i){
            for (int j = i + 3; j <= min(n, i + 6); ++j)
                dp[j] = max(dp[j], (j - i - 1) * dp[i]);
        }
        
        return dp[n];
    }
};