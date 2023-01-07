class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0, length = nums.size();
        for (int i = 0; i < length; ++i){
            if (nums[i] != 0) nums[lastNonZeroFoundAt++] = nums[i];
        }
        
        for (;lastNonZeroFoundAt < length; ++lastNonZeroFoundAt) nums[lastNonZeroFoundAt] = 0;
    }
};