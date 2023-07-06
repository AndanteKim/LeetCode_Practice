class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        
        @lru_cache(maxsize = None)
        def dp(row: int, col: int) -> int:
            if row + col == 0:
                return grid[0][0]
            
            ans = float('inf')
            if row > 0:
                ans = min(ans, dp(row - 1, col))
            
            if col > 0:
                ans = min(ans, dp(row, col - 1))
                
            return ans + grid[row][col]
        
        return dp(len(grid) - 1, len(grid[0]) - 1)