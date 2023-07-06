class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp = [[0] * len(grid[0]) for _ in range(len(grid))]
        dp[0][0] = grid[0][0]
        
        for i in range(1, len(grid[0])):
            dp[0][i] = dp[0][i-1] + grid[0][i]
        
        for i in range(1, len(grid)):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        
        for r in range(1, len(grid)):
            for c in range(1, len(grid[0])):
                dp[r][c] = min(dp[r - 1][c], dp[r][c - 1])+ grid[r][c]
        
        return dp[-1][-1]
        