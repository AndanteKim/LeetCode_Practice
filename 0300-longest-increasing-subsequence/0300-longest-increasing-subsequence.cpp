class Solution {
private:
    int dp(int i, vector<int>& nums, vector<int>& memo){
        if (memo[i] != -1) return memo[i];
        
        int ans = 1;
        for (int j = 0; j < i; ++j){
            if (nums[i] > nums[j])
                ans = max(ans, dp(j, nums, memo) + 1);
        }
        return memo[i] = ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        int ans = 0;
        
        for (int i = 0; i < n; ++i){
            ans = max(ans, dp(i, nums, memo));
        }
        
        return ans;
    }
};