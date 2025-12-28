class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int length = nums.size();
        vector<int> ans(length);
        for (int i = 0,  j = n; i < n && j < length; ++i, ++j){
            ans[2 * i] = nums[i];
            ans[2 * i + 1] = nums[j];
        }

        return ans;
    }
};