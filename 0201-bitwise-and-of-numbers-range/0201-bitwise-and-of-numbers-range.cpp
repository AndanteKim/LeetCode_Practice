class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // Brian Kernighan's algorithm
        while (left < right){
            // Turn off the rightmost 1-bit
            right &= (right - 1);
        }
        
        return right;
    }
};