class Solution:
    def numTilings(self, n: int) -> int:
        def p(n: int) -> int:
            if n == 2:
                return 1
            
            if p_cache[n] != -1:
                return p_cache[n]

            p_cache[n] = (p(n - 1) + f(n - 2)) % mod
            return p_cache[n]

        def f(n: int) -> int:
            if n <= 2:
                return n
            
            if f_cache[n] != -1:
                return f_cache[n]

            f_cache[n] = (f(n - 1) + f(n - 2) + 2 * p(n - 1)) % mod
            return f_cache[n]

        mod = 1_000_000_007
        f_cache, p_cache = [-1] * (n + 1), [-1] * (n + 1)
        return f(n)