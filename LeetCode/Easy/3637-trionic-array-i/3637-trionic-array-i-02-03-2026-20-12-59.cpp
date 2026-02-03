class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums[0] >= nums[1]) return false;
        
        int cnt = 1, n = nums.size();

        for (int i = 2; i < n; ++i) {
            if (nums[i - 1] == nums[i]) return false;

            if (((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i])) < 0) ++cnt;
        }

        return cnt == 3;
    }
};