class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        // Avoid modifying the input directly
        // Create a copy of input array
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n - i - 1; ++j){
                if (nums[j] <= nums[j + 1])
                    // No swap needed
                    continue;
                else{
                    if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1]))
                        // Swap the elements
                        swap(nums[j], nums[j + 1]);
                    else
                        return false;
                }
            }
        }
        
        return true;
    }
};