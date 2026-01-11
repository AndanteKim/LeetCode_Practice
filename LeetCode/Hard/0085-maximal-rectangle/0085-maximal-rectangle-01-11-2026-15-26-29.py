class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        ans, m, n = 0, len(matrix), len(matrix[0])
        dp = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '0':
                    continue

                # Compute the maximum width and update dp with it.
                width = dp[i][j] = dp[i][j - 1] + 1 if j else 1

                # Compute the maximum area rectange with a lower right corner at (i, j)
                for k in range(i, -1, -1):
                    width = min(width, dp[k][j])
                    ans = max(ans, width * (i - k + 1))

        return ans