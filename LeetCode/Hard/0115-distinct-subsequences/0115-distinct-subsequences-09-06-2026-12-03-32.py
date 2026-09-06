class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)

        dp = [0 for j in range(n)]

        for i in range(m - 1, -1, -1):
            prev = 1
            for j in range(n - 1, -1, -1):
                old_dp = dp[j]

                if s[i] == t[j]:
                    dp[j] += prev
                
                prev = old_dp

        return dp[0]