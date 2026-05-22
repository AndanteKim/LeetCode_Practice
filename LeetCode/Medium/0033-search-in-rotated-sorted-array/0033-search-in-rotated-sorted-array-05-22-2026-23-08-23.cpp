class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] > nums.back()) left = mid + 1;
            else right = mid - 1;
        }

        auto bs = [&](int lo, int hi) {
            while (lo <= hi) {
                int mid = lo + ((hi - lo) >> 1);

                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) hi = mid - 1;
                else lo = mid + 1;
            }

            return -1;
        };

        int ans = bs(0, left - 1);

        return ans != -1? ans : bs(left, n - 1);
    }
};