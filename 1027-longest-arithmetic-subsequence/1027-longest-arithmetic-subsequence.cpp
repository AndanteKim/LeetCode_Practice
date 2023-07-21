class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 2;
        vector<unordered_map<int, int>> dp(n);
        
        for (int right = 0; right < n; ++right){
            for (int left = 0; left < right; ++left){
                int diff = nums[right] - nums[left];
                dp[right][diff] = dp[left].count(diff)? dp[left][diff] + 1 : 2;
                ans = max(ans, dp[right][diff]);
            }
        }
        return ans;
    }
};