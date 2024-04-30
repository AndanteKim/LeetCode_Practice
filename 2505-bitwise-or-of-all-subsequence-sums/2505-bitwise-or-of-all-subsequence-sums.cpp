class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        // Array to store the count bits set at each position (0 to 63)
        // Using long long to accommodate large numbers
        vector<long long> bitSetCounts(64);
        long long ans = 0;
        
        for (int n : nums){
            // Loop through each bit postion (0 to 30)
            // since the input numbers are in the range of int
            for (int i = 0; i <= 30; ++i){
                // Check if the ith bit of the current number is set
                if (n & (1 << i))
                    // If yes, increment the count of set bits at that position.
                    ++bitSetCounts[i];
            }
        }
        
        // Loop through each bit position (0 to 62)
        // since we're calculating the OR of subsequences
        for (int i = 0; i <= 62; ++i){
            // If there are any set bits at the current position.
            if (bitSetCounts[i] > 0)
                // Set the corresponding bit in the result
                ans |= 1LL << i;
            
            // Carry over any excess bits to the next position
            bitSetCounts[i + 1] += (bitSetCounts[i] >> 1);
        }
        
        return ans;
    }
};