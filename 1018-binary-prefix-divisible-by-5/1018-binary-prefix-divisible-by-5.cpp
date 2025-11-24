class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size(), false);
        int curr = 0;

        for (int i = 0; i < nums.size(); ++i) {
            curr = ((curr << 1) + nums[i]) % 5;
            ans[i] = (curr == 0);
        }

        return ans;
    }
};