class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        @lru_cache(maxsize = None)
        def dp(row: int, col: int) -> int:
            if col < 0 or col >= n:
                return float('inf')
            
            if row == m - 1:
                return grid[row][col]
            
            min_sum = float('inf')
            
            for i in range(m):
                if col == i:
                    continue
                min_sum = min(min_sum, grid[row][col] + dp(row + 1, i))
            
            return min_sum
        
        m, n = len(grid), len(grid[0])
        return min(dp(0, i) for i in range(m))