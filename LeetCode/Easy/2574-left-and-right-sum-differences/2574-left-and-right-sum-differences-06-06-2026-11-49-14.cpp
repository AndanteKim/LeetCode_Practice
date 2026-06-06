class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n + 1), right(n + 1);

        for (int i = 0; i < n; ++i) {
            left[i + 1] = left[i] + nums[i];
            right[n - 1 - i] = right[n - i] + nums[n - 1 - i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = abs(left[i] - right[i + 1]);
        }

        return ans;
    }
};