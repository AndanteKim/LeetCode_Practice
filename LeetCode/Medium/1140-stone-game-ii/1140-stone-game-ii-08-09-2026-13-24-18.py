class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        def dp(i: int, M: int) -> int:
            if i + 2 * M >= n:
                return suffix[i]

            if memo[i][M] != -1:
                return memo[i][M]

            ans = float('inf')

            for X in range(1, 2 * M + 1):
                ans = min(ans, dp(i + X, max(X, M)))

            memo[i][M] = suffix[i] - ans
            return memo[i][M]

        n = len(piles)
        memo = [[-1] * n for _ in range(n)]

        suffix = piles[:]

        for i in range(n - 2, -1, -1):
            suffix[i] += suffix[i + 1]

        return dp(0, 1)