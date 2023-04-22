class Solution:
    def minWindow(self, s1: str, s2: str) -> str:
        n, m = len(s1), len(s2)
        
        dp = [[10000000000] * (m + 1) for i in range(n + 1)]
        
        dp[0][0], end, length = 0, 0, n + 1
        for i in range(1, length):
            dp[i][0] = 0
            
            for j in range(1, m + 1):
                dp[i][j] = 1 + (dp[i - 1][j - 1] if s1[i - 1] == s2[j - 1]
                                else dp[i - 1][j])
            if dp[i][m] < length:
                length = dp[i][m]
                end = i
        
        return "" if length > n else s1[end - length : end]