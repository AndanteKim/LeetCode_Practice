class Solution:
    def minSteps(self, n: int) -> int:
        ans, d = 0, 2
        
        while n > 1:
            while n % d == 0:
                # If d is prime factor, keep dividing
                # n by d until there is no longer divisible
                n //= d
                ans += d
            d += 1
            
        return ans