class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0;   // Length of longest nice subarray found

        // Tracks bits used in current winbdow
        // Start position of current window
        int usedBits = 0, left = 0;
        for (int right = 0; right < n; ++right){
            while ((usedBits & nums[right]) != 0){
                usedBits ^= nums[left++];   // Remove leftmost element's bits and shrink window from left
            }
            
            // Add current number to the window
            usedBits ^= nums[right];
            
            // Update max length if current window is longer
            ans = max(ans, right - left + 1);
        }


        return ans;
    }
};