class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[0] * n for _ in range(n)]

        for i in range(n):
            dp[i][i] = piles[i]

        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                take_left = piles[i] - dp[i + 1][j]
                take_right = piles[j] - dp[i][j - 1]

                dp[i][j] = max(take_left, take_right)

        return dp[0][n - 1] > 0