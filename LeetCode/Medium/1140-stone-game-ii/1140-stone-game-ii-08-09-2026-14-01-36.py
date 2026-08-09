class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        dp = [[0] * (n + 1) for _ in range(n + 1)]

        suffix = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        for i in range(n + 1):
            dp[i][n] = suffix[i]

        for i in range(n - 1, -1, -1):
            for M in range(n - 1, 0, -1):
                for X in range(1, min(2 * M, n - i) + 1):
                    dp[i][M] = max(dp[i][M], suffix[i] - dp[i + X][max(M, X)])

        return dp[0][1]