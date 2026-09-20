class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        is_pal = [[False] * n for _ in range(n)]

        for length in range(1, n + 1):
            for left in range(n - length + 1):
                right = left + length - 1
                is_pal[left][right] = s[left] == s[right] and (
                    length <= 2 or is_pal[left + 1][right - 1]
                )

        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            dp[i] = dp[i - 1]
            for j in range(i - k + 1):
                if is_pal[j][i - 1]:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        return dp[n]