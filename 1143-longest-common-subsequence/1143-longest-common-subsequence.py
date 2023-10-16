class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n1, n2 = len(text1), len(text2)
        prev_dp, dp = [0] * (n2 + 1), [0] * (n2 + 1)
        
        for i in range(n1 - 1, -1, -1):
            dp = [0] * (n2 + 1)
            for j in range(n2 - 1, -1, -1):
                if text1[i] == text2[j]:
                    dp[j] = 1 + prev_dp[j + 1]
                else:
                    dp[j] = max(prev_dp[j], dp[j + 1])
            prev_dp = dp
        
        return dp[0]
                    