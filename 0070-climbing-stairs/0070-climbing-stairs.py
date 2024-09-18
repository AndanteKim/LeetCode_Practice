class Solution:
    def climbStairs(self, n: int) -> int:
        # Bottom-up
        
        # Base case
        if n <= 2:
            return max(0, n)
        
        dp = [0] * (n + 1)
        dp[1], dp[2] = 1, 2
        
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
            
        return dp[n]