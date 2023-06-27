class Solution:
    def climbStairs(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            if i < 0:
                return 0
            if i == 0:
                return 1
            
            return dp(i - 1) + dp(i - 2)
        
        return dp(n)