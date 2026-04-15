class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) return {{lower, upper}};

        int n = nums.size();
        vector<vector<int>> ans = (lower < nums[0])? vector<vector<int>>{{lower, nums[0] - 1}} : vector<vector<int>>{};

        for (int i = 0; i < n - 1; ++i) {
            if (abs(nums[i] - nums[i + 1]) <= 1) continue;
            ans.push_back({nums[i] + 1, nums[i + 1] - 1});
        }

        if (nums.back() < upper) ans.push_back({nums.back() + 1, upper});

        return ans;
    }
};