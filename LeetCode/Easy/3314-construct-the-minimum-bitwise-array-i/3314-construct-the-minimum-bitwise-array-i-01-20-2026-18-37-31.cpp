class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            bool exist = false;

            for (int num = 0; num < nums[i]; ++num) {
                if ((num | (num + 1)) == nums[i]) {
                    exist = true;
                    ans[i] = num;
                    break;
                }
            }
            if (!exist) ans[i] = -1;
        }

        return ans;
    }
};