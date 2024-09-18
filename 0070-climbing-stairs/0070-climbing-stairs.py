class Solution:
    def climbStairs(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def dp(remain: int) -> int:
            if remain == 0:
                return 1
            if remain < 0:
                return 0
            
            ways = dp(remain - 1)
            ways += dp(remain - 2)
            return ways
        
        return dp(n)
        