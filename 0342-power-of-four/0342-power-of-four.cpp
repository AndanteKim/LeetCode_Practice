class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
        double x = log(n) / (2 * log(2));
        return (int) x == x;
    }
};