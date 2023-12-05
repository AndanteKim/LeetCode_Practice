class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize second pointer and count
        int j = 1, count = 1;
        
        // Start from the second element of the array and process element
        // one by one
        for (int i = 1; i < nums.size(); ++i){
            // If the current element is a duplicate, increment the count
            if (nums[i - 1] == nums[i])
                ++count;
            else
                // Reset the count since we encountered a different element
                // than the previous one
                count = 1;
            
            // For a count <= 2, we copy the element over thus overwriting the element
            // at index "j" in the array
            if (count <= 2){
                nums[j] = nums[i];
                ++j;
            }
        }
        
        return j;
    }
};