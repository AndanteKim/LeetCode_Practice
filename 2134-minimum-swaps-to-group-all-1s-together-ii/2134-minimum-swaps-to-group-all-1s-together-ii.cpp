class Solution {
private:
    // Helper function to calculate the minimum swaps required to group all
    // 'val' together
    int minSwapsHelper(vector<int>& nums, int val){
        int total = 0, n = nums.size();
        
        // Count the total number of 'val' in the array
        for (int i = n - 1; i >= 0; --i){
            if (nums[i] == val)
                ++total;
        }
        
        // If there's no 'val' or the array is full of 'val', no swaps are
        // needed
        if (total == 0 || total == n)
            return 0;
        
        int start = 0, end = 0;
        int maxVal = 0, currVal = 0;
        
        // Initial window setup: count the number of 'val' in the first window
        // of size 'total'
        while (end < total){
            if (nums[end++] == val)
                ++currVal;    
        }
        
        maxVal = max(maxVal, currVal);
        
        // Slide the window across the array to find the maximum number of
        // 'val' in any window
        while (end < n){
            if (nums[start++] == val) --currVal;
            
            if (nums[end++] == val) ++currVal;
            
            maxVal = max(maxVal, currVal);
        }
        
        return total - maxVal;
    }
    
public:
    int minSwaps(vector<int>& nums) {
        // Calculate the minimum swaps needed to group all 1s or all 0s
        // together
        int op1 = minSwapsHelper(nums, 0);   // Grouping 0s together
        int op2 = minSwapsHelper(nums, 1);   // Grouping 1s together
        
        return min(op1, op2);
    }
};