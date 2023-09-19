class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int num : nums){
            if (upper_bound(nums.begin(), nums.end(), num) - lower_bound(nums.begin(), nums.end(), num) > 1)
                return num;
        }
        
        return -1;
    }
};