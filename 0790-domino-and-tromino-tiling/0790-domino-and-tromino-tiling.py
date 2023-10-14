class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 1_000_000_007
        
        @lru_cache(maxsize = None)
        def p(curr: int) -> int:
            if curr == 2:
                return 1
            return (p(curr - 1) + f(curr - 2)) % MOD
        
        @lru_cache(maxsize = None)
        def f(curr: int) -> int:
            if curr <= 2:
                return curr
            return (f(curr - 1) + f(curr - 2) + 2 * p(curr - 1)) % MOD
        
        return f(n)