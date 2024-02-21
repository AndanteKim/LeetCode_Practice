class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right){
            // turn off the rightmost 1-bit
            right = right & (right - 1);
        }
        
        return left & right;
    }
};