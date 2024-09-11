class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorRes = start ^ goal, ans = 0;
        
        // Count the number of 1s in xorRes (differing bits)
        while (xorRes > 0){
            // Increment if the last bit is 1
            ans += xorRes & 1;
            
            // Shift right to process the next bit
            xorRes >>= 1;
        }
        
        return ans;
    }
};