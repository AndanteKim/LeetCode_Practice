class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 1, right = nums.size(), ans = -1;
        
        // Binary search on the length of subarray
        while (left <= right){
            int mid = (left + right) >> 1;
            
            if (hasValidSubarray(nums, k, mid)){
                ans = mid;
                right = mid - 1;    // Try to find smaller length
            }
            else
                left = mid + 1;     // Try larger length
        }
        
        return ans;
    }
    
private:
    // Checks if there exists a subarray of given length whose bitwise OR is >= k
    bool hasValidSubarray(vector<int>& nums, int target, int windowSize){
        vector<int> bitCounts(32);     // Tracks count of set bits at each position
        
        // Sliding window approach
        for (int right = 0; right < nums.size(); ++right){
            // Add current number to window
            updateBitCounts(bitCounts, nums[right], 1);
            
            // Remove leftmost number if window exceeds size
            if (right >= windowSize)
                updateBitCounts(bitCounts, nums[right - windowSize], -1);
            
            // Check if current window is valid
            if (right >= windowSize - 1 && convertBitsToNum(bitCounts) >= target)
                return true;
        }
        
        return false;
    }
    
    // Update bits count array when adding/removing a number from window
    void updateBitCounts(vector<int>& bitCounts, int target, int delta){
        for (int bitPosition = 0; bitPosition < 32; ++bitPosition){
            // Check if bit is set at current position
            if ((target >> bitPosition) & 1) bitCounts[bitPosition] += delta;
        }
    }
    
    // Converts bit count array back to number using OR operation
    int convertBitsToNum(vector<int>& bitCounts){
        int res = 0;
        for (int bitPosition = 0; bitPosition < 32; ++bitPosition){
            if (bitCounts[bitPosition])
                res |= (1 << bitPosition);
        }
        
        return res;
    }
};