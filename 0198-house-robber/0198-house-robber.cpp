class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums[0];
        
        vector<int> dp(n + 1);
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i){
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        
        return dp.back();
    }
};