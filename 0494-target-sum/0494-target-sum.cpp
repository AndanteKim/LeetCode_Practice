class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2 * total + 1));
        dp[0][nums[0] + total] = 1;
        ++dp[0][-nums[0] + total];
        
        for (int i = 1; i < n; ++i){
            for (int sum = -total; sum <= total; ++sum){
                if (dp[i - 1][sum + total] > 0){
                    dp[i][sum + total + nums[i]] += dp[i - 1][sum + total];
                    dp[i][sum + total - nums[i]] += dp[i - 1][sum + total];
                }
            }
        }
        
        return abs(target) > total? 0 : dp[n - 1][target + total];
    }
};