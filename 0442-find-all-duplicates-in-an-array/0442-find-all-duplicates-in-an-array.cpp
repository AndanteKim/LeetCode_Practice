class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // one pass implement
        vector<int> ans;
        
        for (int num:nums){
            if (nums[abs(num) - 1] < 0){
                // seen before
                ans.push_back(abs(num));
            }
            
            nums[abs(num) - 1] *= -1;
        }
        
        return ans;
    }
};