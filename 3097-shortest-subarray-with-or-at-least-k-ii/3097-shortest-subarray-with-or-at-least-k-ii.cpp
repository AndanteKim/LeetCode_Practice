class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = std::numeric_limits<int>::max();
        int left = 0;
        vector<int> bitCounts(32);  // Tracks count of set bits at each position
        
        // Expand window until end of array
        for (int right = 0; right < n; ++right){
            // Add current numbert to window
            updateBitCounts(bitCounts, nums[right], 1);
            
            // Contract window while OR value is valid
            while (left <= right && convertBitToNum(bitCounts) >= k){
                // Update minimum length found so far
                ans = min(ans, right - left + 1);
                
                // Remove leftmost number and shrink window
                updateBitCounts(bitCounts, nums[left++], -1);
            }
        }
        
        return (ans == std::numeric_limits<int>::max())? -1 : ans;
    }
    
private:
    // Updates bit count array when adding/removing a number from window
    void updateBitCounts(vector<int>& bitCounts, int num, int delta){
        // Check if bit is set at current position
        for (int i = 0; i < 32; ++i){
            if ((num >> i) & 1)
                bitCounts[i] += delta;
        }
    }
    
    // Converts bit count array back to number using OR operation
    int convertBitToNum(const vector<int>& bitCounts){
        int res = 0;
        for (int bitPosition = 0; bitPosition < 32; ++bitPosition){
            if (bitCounts[bitPosition])
                res |= (1 << bitPosition);
        }
        
        return res;
    }
};