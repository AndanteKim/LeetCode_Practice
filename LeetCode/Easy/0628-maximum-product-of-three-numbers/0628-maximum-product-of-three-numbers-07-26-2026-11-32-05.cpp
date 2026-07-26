class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        return max(nums[0] * nums[1] * nums.back(), nums[n - 3] * nums[n - 2] * nums.back());
    }
};