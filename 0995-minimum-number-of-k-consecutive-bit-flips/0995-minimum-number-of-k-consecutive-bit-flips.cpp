class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        // Track the current number of flips
        int currFlip = 0;
        // Track the total number of flips
        int totalFlip = 0;
        
        for (int i = 0; i < n; ++i){
            // If the window slides out of the range and the leftmost element is marked as flipped (2)
            // decrement the current flip by 1
            if (i >= k && nums[i - k] == 2){
                --currFlip;
            }
            
            // Check if the current bit needs to be flipped
            if (currFlip % 2 == nums[i]){
                // If flipping would exceed array bounds, return -1
                if (i + k > n) return -1;
                
                // Mark the current bit as flipped
                nums[i] = 2;
                ++currFlip;
                ++totalFlip;
            }
        }
        
        return totalFlip;
    }
};