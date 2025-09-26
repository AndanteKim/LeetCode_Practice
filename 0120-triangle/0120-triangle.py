class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        @lru_cache(maxsize = None)
        def dp(row: int, col: int) -> int:
            if row == n:
                return 0
            
            if col == len(triangle[row]):
                return float('inf')

            min_path = float('inf')
            min_path = triangle[row][col] + min(dp(row + 1, col), dp(row + 1, col + 1))
            
            return min_path

        n = len(triangle)
        return dp(0, 0)