class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        if (accumulate(nums.begin(), nums.end(), 0) == n) return n - 1;
        
        vector<pair<int, int>> dp(n);
        dp[0].first = nums[0];
        
        for (int i = 1; i < n; ++i){
            if (nums[i] == 1){
                dp[i].first = dp[i - 1].first + 1;
                dp[i].second = dp[i - 1].second + 1;
            }
            else{
                dp[i].first = 0;
                dp[i].second = dp[i - 1].first;
            }
            ans = max(ans, max(dp[i].first, dp[i].second));
        }
        
        return ans;
    }
};