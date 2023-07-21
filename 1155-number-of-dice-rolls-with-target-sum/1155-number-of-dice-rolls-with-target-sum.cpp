class Solution {
private:
    int MOD = 1'000'000'007;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[n][target] = 1;
        
        for (int diceIndex = n - 1; diceIndex >= 0; --diceIndex){
            for (int currSum = 0; currSum <= target; ++currSum){
                int ways = 0;
                for (int i = 1; i <= min(k, target - currSum); ++i)
                    ways = (ways + dp[diceIndex + 1][currSum + i]) % MOD;
                dp[diceIndex][currSum] = ways;
            }
        }
        return dp[0][0];
    }
};