class Solution:
    def countSubstrings(self, s: str) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, prev: str) -> int:
            if i == n:
                return 0
            
            curr, ways = prev + s[i], 0
            if curr == curr[::-1]:
                ways = 1 + dp(i + 1, curr)
            else:
                ways = dp(i + 1, curr)
            
            return ways
        
        n = len(s)
        return sum(dp(i, "") for i in range(n))
            
        