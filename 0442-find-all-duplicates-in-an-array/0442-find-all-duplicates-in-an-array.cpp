class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        // two pass implement
        for (int num: nums)
            nums[abs(num) - 1] *= -1;
        
        for (int num:nums){
            if (nums[abs(num) - 1] > 0){
                ans.push_back(abs(num));
                nums[abs(num) - 1] *= -1;
            }
        }
        
        return ans;
    }
};