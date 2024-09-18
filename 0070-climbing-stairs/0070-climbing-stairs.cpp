class Solution {
public:
    int climbStairs(int n) {
        // Bottom-up space-optimized
        // Base case
        if (n <= 2) return max(0, n);
        
        int first = 1, second = 2;
        
        for (int i = 3; i <= n; ++i){
            int third = first + second;
            first = second;
            second = third;
        }
        
        return second;
    }
};