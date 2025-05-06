class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans = nums, temp = nums;
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            temp[i] = nums[i];
            ans[i] = nums[temp[i]];
        }

        return ans;
    }
};