class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        for (int curr = 1, lastZeroFoundAt = 0; curr < nums.size(); ++curr){
            if (nums[curr] != 0 and nums[lastZeroFoundAt] == 0){
                swap(nums[lastZeroFoundAt], nums[curr]);
            }
            
            while (nums[lastZeroFoundAt] != 0 && lastZeroFoundAt < curr) ++lastZeroFoundAt;
        }
        
    }
};