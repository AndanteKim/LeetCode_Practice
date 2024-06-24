class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // validFlipsFromPastWindow := tracks valid flips within the past window
        // flipCount := counts totaal flips needed
        int n = nums.size(), flipCount = 0, validFlipsFromPastWindow = 0;
        // Keep track of flipped states
        vector<bool> flipped(n);
        
        for (int i = 0; i < n; ++i){
            if (i >= k){
                // Decrease the count of valid flips from the past window if needed
                if (flipped[i - k])
                    --validFlipsFromPastWindow;
            }
            
            // Check if the current bit needs to be flipped
            if (validFlipsFromPastWindow % 2 == nums[i]){
                // If flipping the window extends beyond the array length
                // return -1
                if (i + k > n)
                    return -1;
                
                // Increment the count of valid flips and
                // mark current as flipped
                flipped[i] = true;
                ++validFlipsFromPastWindow;
                ++flipCount;
            }
        }
        
        return flipCount;
    }
};