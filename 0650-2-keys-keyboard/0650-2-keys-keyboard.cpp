class Solution {
public:
    int minSteps(int n) {
        int ans = 0, d = 2;
        
        while (n > 1){
            // If d is prime number, keep dividing 
            // n by d until there's no longer divisible.
            while (n % d == 0){
                n /= d;
                ans += d;
            }
            ++d;
        }
        
        return ans;
    }
};