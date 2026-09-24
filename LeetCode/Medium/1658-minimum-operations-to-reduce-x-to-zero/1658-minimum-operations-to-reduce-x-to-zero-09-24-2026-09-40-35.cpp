class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left = 0, n = nums.size();
        int mn = std::numeric_limits<int>::max();
        int curr = accumulate(nums.begin(), nums.end(), 0);

        for (int right = 0; right < n; ++right) {
            curr -= nums[right];

            while (curr < x && left <= right) {
                curr += nums[left++];
            }

            if (curr == x) mn = min(mn, n - 1 - right + left);
        }

        return mn != std::numeric_limits<int>::max()? mn : -1;
    }
};