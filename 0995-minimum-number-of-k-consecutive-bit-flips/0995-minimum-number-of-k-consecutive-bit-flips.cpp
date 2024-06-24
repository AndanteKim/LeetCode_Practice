class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        // Queue to keep track of flips
        // Current flip state
        int res = 0, flipped = 0;
        // Total number of flips
        deque<int> flipQueue;
        
        for (int i = 0; i < n; ++i){
            // Remove the effect of the oldest flip if it's out of the current
            // window
            if (i >= k){
                flipped ^= flipQueue.front();
                flipQueue.pop_front();
            }
            
            // If the current bit is 0, it needs to be flipped
            if (flipped == nums[i]){
                // If we cannot flip a subarray starting at index i
                if (i + k > n)
                    return -1;
                // Add a flip at this position
                flipQueue.push_back(1);
                // Toggle the flipped state
                flipped ^= 1;
                // Increment the flip count
                ++res;
            }
            else flipQueue.push_back(0);
        }
        
        return res;
    }
};