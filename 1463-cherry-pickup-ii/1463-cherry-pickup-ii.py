class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        @lru_cache(maxsize = None)
        def dp(row: int, col1: int, col2: int) -> int:
            if col1 < 0 or col1 >= n or col2 < 0 or col2 >= n:
                return float('-inf')
            
            # Current cell
            ans = 0
            ans += grid[row][col1]
            if col1 != col2:
                ans += grid[row][col2]
            
            # transition
            if row != m - 1:
                ans += max(dp(row + 1, new_col1, new_col2) for new_col1 in [col1, col1 + 1, col1 - 1] for new_col2 in [col2, col2 + 1, col2 - 1])
            
            return ans
        
        m, n = len(grid), len(grid[0])
        return dp(0, 0, n - 1)