class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(3);
        dp[0] = true;
        
        for (int i = 0; i < n; ++i){
            int dpIndex = i + 1;
            bool ans = false;
            if (i > 0 && nums[i] == nums[i - 1])
                ans |= dp[(dpIndex - 2) % 3];
            if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
                ans |= dp[(dpIndex - 3) % 3];
            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)
                ans |= dp[(dpIndex - 3) % 3];
            dp[dpIndex % 3] = ans;
        }
        return dp[n % 3];
    }
};