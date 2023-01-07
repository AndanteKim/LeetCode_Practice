class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, curr = 0; curr < nums.size(); ++curr){
            if (nums[curr] != 0){
                swap(nums[curr], nums[lastNonZeroFoundAt++]);
                
            }
            
        }
    }
};