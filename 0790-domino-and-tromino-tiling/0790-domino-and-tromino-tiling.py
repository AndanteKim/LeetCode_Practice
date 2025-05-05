class Solution:
    def numTilings(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def p(n):
            if n == 2:
                return 1
            
            return (p(n - 1) + f(n - 2)) % mod

        @lru_cache(maxsize = None)
        def f(n):
            if n <= 2:
                return n
            return (f(n - 1) + f(n - 2) + 2 * p(n - 1)) % mod
        
        mod = 1_000_000_007
        return f(n)