class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int prefixLen = 1, n = nums.size();

        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) ++prefixLen;
            else break;
        }

        int total = (nums[prefixLen - 1] + nums[0]) * prefixLen >> 1;

        while (numSet.contains(total)) ++total;
        return total;
    }
};