class Solution {
    int dp[101][101][101];
    int mod = 1e9 + 7;
    
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profits) {
        memset(dp, 0, sizeof(dp));
        
        for (int count = 0; count <= n; ++count) dp[group.size()][count][minProfit] = 1;
        
        for (int index = group.size() - 1; index >= 0; --index){
            for (int count = 0; count <= n; ++count){
                for (int profit = 0; profit <= minProfit; ++profit){
                    dp[index][count][profit] = dp[index + 1][count][profit];
                    if (group[index] + count <= n){
                        dp[index][count][profit] = (dp[index][count][profit] + dp[index + 1][count + group[index]]\
                                                    [min(minProfit, profit + profits[index])]) % mod;
                    }
                }
            }
        }
        
        return dp[0][0][0];
    }
};