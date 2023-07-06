class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        @lru_cache(maxsize = None)
        def dp(i: int, j: int) -> int:
            if i + j == 0:
                return 1
            
            ways = 0
            if i > 0:
                ways += dp(i - 1, j)
            
            if j > 0:
                ways += dp(i, j - 1)
            
            return ways
        
        return dp(m - 1, n - 1)
        