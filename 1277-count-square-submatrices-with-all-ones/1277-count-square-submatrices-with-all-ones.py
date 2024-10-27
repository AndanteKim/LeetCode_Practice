class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        def solve(i: int, j: int) -> int:
            # If the cell lies outside the grid, return 0
            if i >= m or j >= n:
                return 0
            
            if not matrix[i][j]:
                return 0
            
            # If we've already visited this cell, return the memoized value.
            if dp[i][j] != -1:
                return dp[i][j]
            
            # Find the answer for the cell to the right of the current cell.
            right = solve(i, j + 1)
            
            # Find the answer for the cell to the diagonal of the current cell.
            diagonal = solve(i + 1, j + 1)
            
            # Find the answer for the cell to the below of the current cell.
            below = solve(i + 1, j)
            dp[i][j] = 1 + min(right, diagonal, below)
            return dp[i][j]
            
        m, n, ans = len(matrix), len(matrix[0]), 0
        dp = [[-1] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                ans += solve(i, j)
                
        return ans