class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # Top-down DP
        def min_path(row: int, col: int) -> int:
            path = triangle[row][col]
            if memo[row][col] != -1:
                return memo[row][col]
            
            if row < len(triangle) - 1:
                path += min(min_path(row + 1, col), min_path(row + 1, col + 1))
            memo[row][col] = path
            return path
        
        m = len(triangle)
        memo = [[-1] * len(triangle[i]) for i in range(m)]
        return min_path(0, 0)