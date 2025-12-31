class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        for (int num : nums) {
            int newIdx = abs(num) - 1;

            if (nums[newIdx] > 0) nums[newIdx] *= -1;
        }


        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] > 0) ans.push_back(i);
        }

        return ans;
    }
};