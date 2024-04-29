class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0, count = 0;
        for (int n:nums) finalXor ^= n;
        
        // Keep iterating until any of k or finalXor becomes zero.
        while (k > 0 || finalXor > 0){
            // k % 2 returns the rightmost bit in k.
            // finalXor % 2 returns the rightmost bit in finalXor.
            if ((finalXor % 2) != (k % 2))
                ++count;
            
            // Remove the rightmost bit
            k >>= 1;
            finalXor >>= 1;
        }
        
        return count;
    }
};