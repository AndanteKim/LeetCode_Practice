class Solution:
    def countVowelPermutation(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, prev) -> int:
            if i == 0:
                return 1
            
            ways = 0
            for c in sequence[prev]:
                ways += dp(i - 1, c)
                ways %= MOD
            return ways
        
        sequence = {'a': ('e',), 'e': ('a', 'i'), 'i': ('a', 'e', 'o', 'u'), 'o': ('i', 'u'),\
                   'u': ('a',)}
        MOD = 1_000_000_007
        return sum(dp(n - 1, c) for c in ('a', 'e', 'i', 'o', 'u')) % MOD