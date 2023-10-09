class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return vector<int>{-1, -1};
        
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        return (first >= nums.size() || nums[first] != target)? vector<int>{-1, -1}: vector<int>{first, last - 1}; 
    }
};