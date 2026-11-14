class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = std::numeric_limits<int>::max(), n = nums.size();

        for (int left = 0; left < n; ++left) {
            int curr = 0;

            for (int right = left; right < min(n, left + r); ++right) {
                curr += nums[right];
                if (curr > 0 && right - left + 1 >= l) ans = min(ans, curr);
            }
        }

        return ans == std::numeric_limits<int>::max()? -1 : ans;
    }
};