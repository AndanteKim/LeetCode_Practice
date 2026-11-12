class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, mx = 1;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                ++inc;
                dec = 1;
            }
            else if (nums[i] > nums[i + 1]) {
                inc = 1;
                ++dec;
            }
            else {
                inc = 1;
                dec = 1;
            }
            mx = max(mx, max(inc, dec));
        }

        return mx;
    }
};