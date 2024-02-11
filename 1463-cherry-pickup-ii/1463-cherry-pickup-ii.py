class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[[0] * n for __ in range(n)] for _ in range(m)]
        
        for row in range(m - 1, -1, -1):
            for col1 in range(n):
                for col2 in range(n):
                    ans = 0
                    # Current cell
                    ans += grid[row][col1]
                    
                    if col1 != col2:
                        ans += grid[row][col2]
                    
                    # transition
                    if row != m - 1:
                        curr = 0
                        for new_col1 in range(col1 - 1, col1 + 2):
                            for new_col2 in range(col2 - 1, col2 + 2):
                                if new_col1 >= 0 and new_col1 < n and new_col2 >= 0 and new_col2 < n:
                                    curr = max(curr, dp[row + 1][new_col1][new_col2])
                        
                        ans += curr
                    
                    dp[row][col1][col2] = ans
                    
        return dp[0][0][n - 1]