class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        ans = grid[:]
        m, n = len(grid), len(grid[0])

        for j in range(y, y + k):
            rows = []
            for i in range(x, x + k):
                rows.append(grid[i][j])

            for i in range(x, x + k):
                ans[i][j] = rows.pop()

        return ans