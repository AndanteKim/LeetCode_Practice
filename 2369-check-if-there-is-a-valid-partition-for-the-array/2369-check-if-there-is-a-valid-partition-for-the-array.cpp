class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        
        for (int i = 0; i < n; ++i){
            int dpIndex = i + 1;
            if (i > 0 && nums[i] == nums[i - 1]) dp[dpIndex] = dp[dpIndex] | dp[dpIndex - 2];
            if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) dp[dpIndex] = dp[dpIndex] | dp[dpIndex - 3];
            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] + 1 == nums[i - 2] + 2) dp[dpIndex] = dp[dpIndex] | dp[dpIndex - 3];
        }
        
        return dp[n];
    }
};