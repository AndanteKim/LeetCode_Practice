class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size(), total = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) total += nums[i];
            else break;
        }

        unordered_set<int> numSet(nums.begin(), nums.end());

        while (numSet.contains(total)) ++total;
        return total;
    }
};