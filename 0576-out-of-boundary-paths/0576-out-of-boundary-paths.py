class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, j: int, remain: int) -> int:
            if i < 0 or i >= m or j < 0 or j >= n:
                return 1 if remain >= 0 else 0
            
            if remain == 0:
                return 0

            ways = dp(i + 1, j, remain - 1) % mod
            ways = (ways + dp(i - 1, j, remain - 1)) % mod
            ways = (ways + dp(i, j + 1, remain - 1)) % mod
            ways = (ways + dp(i, j - 1, remain - 1)) % mod
            
            return ways
        
        mod = 1_000_000_007
        return dp(startRow, startColumn, maxMove) % mod