class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        row_cnt, col_cnt = [0] * m, [0] * n

        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    row_cnt[i] += 1
                    col_cnt[j] += 1

        ans = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    if row_cnt[i] > 1 or col_cnt[j] > 1:
                        ans += 1

        return ans