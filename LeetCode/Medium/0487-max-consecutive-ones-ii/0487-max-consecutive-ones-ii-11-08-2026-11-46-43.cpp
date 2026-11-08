class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), ans = 0, curr = 0;
        int left = 0, count = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == 0) ++count;

            while (left < right && count >= 2) {
                if (nums[left++] == 0) --count;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};