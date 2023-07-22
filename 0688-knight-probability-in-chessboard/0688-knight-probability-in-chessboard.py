class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        directions = [(1, 2), (1, -2), (-1, 2), (-1, -2),
                      (2, 1), (2, -1), (-2, 1), (-2, -1)]
        
        dp = [[[0] * n for _ in range(n)] for _ in range(k + 1)]
        dp[0][row][column] = 1
        
        for moves in range(1, k + 1):
            for r in range(n):
                for c in range(n):
                    for dr, dc in directions:
                        prev_r, prev_c = r - dr, c - dc
                        if 0 <= prev_r < n and 0 <= prev_c < n:
                            dp[moves][r][c] += dp[moves - 1][prev_r][prev_c]
                    dp[moves][r][c] /= 8
        
        prob = sum(dp[k][i][j] for i in range(n) for j in range(n))
        
        return prob