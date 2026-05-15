class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int n = nums.size();
        int left = 0, right = n - 1;

        if (nums.back() > nums[0]) return nums[0];

        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if (nums[mid - 1] > nums[mid]) return nums[mid];

            if (nums[0] < nums[mid]) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};