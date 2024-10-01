class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Base case
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1, 1};
        vector<int> prevDp{1, 1};
        
        // Space optimized algorithm
        for (int n = 2; n <= rowIndex; ++n){
            vector<int> dp(n + 1);
            dp[0] = 1, dp.back() = 1;
            
            for (int i = 1; i < n; ++i)
                dp[i] = prevDp[i - 1] + prevDp[i];
            prevDp = dp;
        }
        
        return prevDp;
    }
};