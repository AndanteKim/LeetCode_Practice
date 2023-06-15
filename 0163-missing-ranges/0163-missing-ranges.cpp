class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) return {{lower, upper}};
        vector<vector<int>> ans;
        if (nums[0] - lower >= 1) ans.push_back({lower, nums[0] - 1});
        for (int i = 0; i < nums.size() - 1; ++i){
            if (nums[i + 1] - nums[i] > 1) ans.push_back({nums[i] + 1, nums[i + 1] - 1});
        }
        if (upper - nums.back() >= 1) ans.push_back({nums.back() + 1, upper});
        return ans;
    }
};