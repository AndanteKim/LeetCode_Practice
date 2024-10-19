class Solution {
public:
    char findKthBit(int n, int k) {
        // Length of Sn is 2^n - 1
        int invertCount = 0, length = (1 << n) - 1;
        
        while (k > 1){
            // If k is in the middle, return based on inversion count
            if (k == (length >> 1) + 1)
                return (invertCount % 2 == 0)? '1' : '0';
            
            // If k is in the second half, invert and mirror
            if (k > (length >> 1)){
                ++invertCount;      // Increment inversion count
                k = length + 1 - k; // Mirror position 
            }
            
            length >>= 1;   // Reduce length for next iteration
        }
        
        // For the first position, return based on inversion count
        return (invertCount % 2 == 0)? '0' : '1';
    }
};