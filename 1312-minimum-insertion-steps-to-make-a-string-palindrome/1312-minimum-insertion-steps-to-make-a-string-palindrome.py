class Solution:
    def lcs(self, s1: str, s2: str, m: int, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        
        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 or j == 0:
                    dp[i][j] = 0
                elif s1[i - 1] == s2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[m][n]
    
    def minInsertions(self, s: str) -> int:
        n = len(s)
        sRev = s[::-1]
        return n - self.lcs(s, sRev, n, n)