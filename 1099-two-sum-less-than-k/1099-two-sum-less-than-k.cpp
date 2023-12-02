class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        for (int i = 0; i < nums.size(); ++i){
            int j = lower_bound(nums.begin() + i, nums.end(), k - nums[i]) - nums.begin() - 1;
            if (j > i)
                ans = max(ans, nums[i] + nums[j]);
        }
        
        return ans;
    }
};