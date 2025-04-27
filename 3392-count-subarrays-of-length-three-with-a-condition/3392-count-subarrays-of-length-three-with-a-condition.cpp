class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0, n = nums.size();

        for (int i = 0; i < n - 2; ++i){
            if (nums[i + 1] == (nums[i] + nums[i + 2]) * 2) ++ans;
        }

        return ans;
    }
};