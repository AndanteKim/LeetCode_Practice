class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans, flatten = [[0] * n for _ in range(m)], []

        for i in range(m):
            for j in range(n):
                flatten.append(grid[i][j])
        
        for i in range(m):
            for j in range(n):
                ans[i][j] = flatten[(i * n + j - k) % (m * n)]

        return ans