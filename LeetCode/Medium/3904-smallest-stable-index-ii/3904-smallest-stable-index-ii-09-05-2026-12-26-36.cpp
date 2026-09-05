class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        int maxAtAns = -1, currMax = maxAtAns;

        for (int i = 0; i < n; ++i) {
            currMax = max(currMax, nums[i]);

            if (i == ans) maxAtAns = max(maxAtAns, nums[i]);

            if (nums[i] < maxAtAns - k) {
                ans = i + 1;
                maxAtAns = currMax;
            }
        }

        return ans < n? ans : -1;
    }
};