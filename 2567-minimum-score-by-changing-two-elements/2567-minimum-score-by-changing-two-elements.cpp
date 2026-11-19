class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return min(nums.back() - nums[2], min(nums[n - 2] - nums[1], nums[n - 3] - nums[0]));
    }
};