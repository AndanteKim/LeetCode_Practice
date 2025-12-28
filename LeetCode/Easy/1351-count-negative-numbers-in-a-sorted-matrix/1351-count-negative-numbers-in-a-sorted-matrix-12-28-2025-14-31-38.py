class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans, j = 0, n - 1

        for row in grid:
            while j >= 0 and row[j] < 0:
                j -= 1
            ans += n - (j + 1)

        return ans