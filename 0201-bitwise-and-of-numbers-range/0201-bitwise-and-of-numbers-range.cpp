class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // Brian Kernighan's algorithm
        while (left < right){
            // Turn off the rightmost bits
            right &= (right - 1);
        }
        
        return right;
    }
};