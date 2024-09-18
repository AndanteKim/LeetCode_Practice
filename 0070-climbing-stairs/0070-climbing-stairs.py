class Solution:
    def climbStairs(self, n: int) -> int:
        # Bottom-up, space-optimized
        
        # Base case
        if n <= 2:
            return max(n, 0)
        
        first, second, ans = 1, 2, 0
        
        for _ in range(3, n + 1):
            ans = first + second
            first = second
            second = ans
            
        return ans