class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;

        for (int i = 0; i < n - 1; ++i) {
            left += nums[i];
            right -= nums[i];

            if (abs(left - right) % 2 == 0) ++ans;
        }

        return ans;
    }
};