class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # Top-down DP
        @lru_cache(maxsize = None)
        def min_path(row: int, col: int) -> int:
            path = triangle[row][col]
            if row < len(triangle) - 1:
                path += min(min_path(row + 1, col), min_path(row + 1, col + 1))
            return path
        
        return min_path(0, 0)