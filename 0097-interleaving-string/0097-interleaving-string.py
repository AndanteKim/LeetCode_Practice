class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1, n2, n3 = len(s1), len(s2), len(s3)
        if n3 != n1 + n2:
            return False
        
        dp = [False] * (n2 + 1)
        
        for i in range(n1 + 1):
            for j in range(n2 + 1):
                if i == 0 and j == 0:
                    dp[j] = True
                elif i == 0:
                    dp[j] = dp[j - 1] and s2[j - 1] == s3[i + j - 1]
                elif j == 0:
                    dp[j] = dp[j] and s1[i - 1] == s3[i + j - 1]
                else:
                    dp[j] = (dp[j - 1] and s2[j - 1] == s3[i + j - 1]) or (dp[j] and s1[i - 1] == s3[i + j - 1])
        
        return dp[n2]