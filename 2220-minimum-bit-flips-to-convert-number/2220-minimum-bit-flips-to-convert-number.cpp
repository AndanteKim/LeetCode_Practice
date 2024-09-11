class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        
        // Use bitmask to check whether we need to convert or not each digit.
        while (start > 0 || goal > 0){
            if ((start & 1) != (goal & 1)) ++ans;
            
            // right shift to check
            start >>= 1;
            goal >>= 1;
        }
        
        return ans;
    }
};