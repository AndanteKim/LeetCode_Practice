class Solution:
    def knightDialer(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def dp(prev: int, remain: int) -> int:
            if remain == 0:
                return 1
            
            ways = 0
            for curr in available[prev]:
                ways = (ways + dp(curr, remain - 1)) % 1_000_000_007
                
            return ways
            
        available = {0:(4,6), 1:(6,8), 2:(7,9), 3:(4, 8),\
                    4:(0,3,9), 5:tuple(), 6:(0,1,7), 7:(2,6),\
                    8:(1,3), 9:(2,4)}
        return sum(dp(i, n - 1) for i in range(10)) % 1_000_000_007