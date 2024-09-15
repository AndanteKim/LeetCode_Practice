class Solution {
public:
    int mySqrt(int x) {
        // Newton's method
        if (x < 2)
            return x;
        
        double x0 = x;
        double x1 = (x0 + x / x0) / 2.0;
        
        while (abs(x0 - x1) >= 1){
            x0 = x1;
            x1 = (x0 + x / x0) / 2.0;
        }
        
        return static_cast<int>(x1);
    }
};