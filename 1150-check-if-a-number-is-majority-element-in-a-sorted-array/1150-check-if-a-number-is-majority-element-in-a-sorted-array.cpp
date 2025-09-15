class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin(), right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        return (right - left) > (nums.size() >> 1)? true : false;
    }
};