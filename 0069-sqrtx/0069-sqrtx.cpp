class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        long left = mySqrt(x >> 2) << 1;
        long right = left + 1;
        return (right * right > x)? left : right;
    }
};