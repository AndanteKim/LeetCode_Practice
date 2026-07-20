class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                new_c = (j + k) % n
                wrap_around_cnt = (j + k) // n
                new_r = (i + wrap_around_cnt) % m
                ans[new_r][new_c] = grid[i][j]

        return ans