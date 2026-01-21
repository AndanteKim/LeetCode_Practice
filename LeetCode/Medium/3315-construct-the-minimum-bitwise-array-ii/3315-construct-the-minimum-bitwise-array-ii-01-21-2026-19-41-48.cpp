class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            int num = nums[i], curr = -1, d = 1;

            while ((num & d) != 0) {
                curr = num - d;
                d <<= 1;
            }

            ans[i] = curr;
        }

        return ans;
    }
};