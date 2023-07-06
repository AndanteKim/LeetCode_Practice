class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [float('inf')] * n
        dp[0] = 0
        
        for row in range(m):
            next_row = [0] * n
            for col in range(n):
                next_row[col] = dp[col]
                if col > 0:
                    next_row[col] = min(next_row[col], next_row[col - 1])
                next_row[col] += grid[row][col]
            dp = next_row
        
        return dp[n - 1]
        