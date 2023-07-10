class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(2 * total + 1);
        dp[nums[0] + total] = 1;
        ++dp[-nums[0] + total];
        
        for (int i = 1; i < nums.size(); ++i){
            vector<int> nxt(2 * total + 1);
            for (int sum = -total; sum <= total; ++sum){
                if (dp[sum + total] > 0){
                    nxt[sum + total + nums[i]] += dp[sum + total];
                    nxt[sum + total - nums[i]] += dp[sum + total];
                }
            }
            dp = nxt;
        }
        
        return (abs(target) > total)? 0 : dp[target + total];
    }
};