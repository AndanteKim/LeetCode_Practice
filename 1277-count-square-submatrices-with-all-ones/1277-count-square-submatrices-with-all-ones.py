class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n, ans = len(matrix), len(matrix[0]), 0
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j]:
                    # min(right, diagonal, left) + 1
                    dp[i + 1][j + 1] = 1 + min(dp[i][j + 1], dp[i][j], dp[i + 1][j])
                    ans += dp[i + 1][j + 1]
        return ans