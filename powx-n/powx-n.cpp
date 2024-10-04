class Solution {
private:
    double binaryExp(double x, long long n){
        // Base case
        if (x == 0) return 0;
        
        if (n == 0) return 1;
        
        if (n < 0) return (double) 1.0 / binaryExp(x, -n);
        
        return n % 2? x * binaryExp(x * x, (n - 1) >> 1) : binaryExp(x * x, n >> 1);
    }
    
public:
    double myPow(double x, int n) {
        return binaryExp(x, (long long)n);
    }
};