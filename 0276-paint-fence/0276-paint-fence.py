class Solution:
    def numWays(self, n: int, k: int) -> int:
        @lru_cache(maxsize = None)
        def total_ways(i: int) -> int:
            if i == 1:
                return k
            
            if i == 2:
                return k * k
            
            return (k - 1) * (total_ways(i - 1) + total_ways(i - 2))
        
        return total_ways(n)