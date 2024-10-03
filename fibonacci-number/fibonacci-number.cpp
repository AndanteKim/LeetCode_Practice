class Solution {
public:
    int fib(int n) {
        // Base case
        if (n <= 1) return n;
        
        int first = 0, second = 1;
        
        // Bottom-up with space optimization
        int third;
        for (int i = 2; i <= n; ++i){
            third = first + second;
            first = second;
            second = third;
        }
        
        return second;
    }
};