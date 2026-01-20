class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int d = 1, ans = -1;

            while ((nums[i] & d) != 0) {
                ans = nums[i] - d;
                d <<= 1;
            }
            nums[i] = ans;
        }

        return nums;
    }
};