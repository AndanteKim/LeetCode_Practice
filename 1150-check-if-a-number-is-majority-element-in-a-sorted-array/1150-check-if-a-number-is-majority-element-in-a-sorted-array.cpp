class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin(), left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        double half = nums.size() / 2;
        
        return (right - left > half)? true : false;
    }
};