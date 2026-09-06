class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        @lru_cache(maxsize=None)
        def dp(i: int, j: int) -> int:
            # Base case
            if j == n:
                return 1
            
            if i == m:
                return 0

            if memo[i][j] != -1:
                return memo[i][j]

            cnt = 0
            if s[i] == t[j]:
                cnt += dp(i + 1, j + 1)
            cnt += dp(i + 1, j)

            memo[i][j] = cnt
            return memo[i][j]
        
        m, n = len(s), len(t)
        memo = [[-1] * n for _ in range(m)]
        return dp(0, 0)