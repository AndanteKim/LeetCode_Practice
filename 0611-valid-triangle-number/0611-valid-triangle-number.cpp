class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i){
            for (int j = i + 1; j < n - 1 && nums[i] != 0; ++j){
                ans += (lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin()) - j - 1;
            }
        }

        return ans;
    }
};