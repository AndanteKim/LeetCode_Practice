class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        @lru_cache(maxsize=None)
        def dp(i: int, j: int) -> int:
            # Base case
            if j == n:
                return 1
            
            if i == m:
                return 0

            cnt = 0

            if s[i] == t[j]:
                cnt += dp(i + 1, j + 1)
            cnt += dp(i + 1, j)

            return cnt
        
        m, n = len(s), len(t)
        return dp(0, 0)