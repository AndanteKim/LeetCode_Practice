class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        
        for (int i = 1; i < n - 1; ++i) dp[i] = min(dp[i - 1], nums[i]);
        int mx = nums[n - 1];
        for (int i = n - 2; i > 0; --i){
            int mn = dp[i - 1];
            mx = max(mx, nums[i + 1]);
            if (mn < nums[i] && nums[i] < mx) return true;
        }
        
        return false;
    }
};