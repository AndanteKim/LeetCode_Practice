typedef unsigned long long ull;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<ull> dp(target + 1);
        dp[0] = 1;
        
        for (int combSum = 0; combSum <= target; ++combSum){
            for (int num : nums){
                if (combSum - num >= 0)
                    dp[combSum] += dp[combSum - num];
                else
                    break;
            }
        }
        
        return dp[target];
    }
};