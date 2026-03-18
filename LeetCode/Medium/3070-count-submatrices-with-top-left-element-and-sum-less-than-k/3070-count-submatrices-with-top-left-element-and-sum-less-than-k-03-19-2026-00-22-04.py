class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        cols, ans = [0] * n, 0

        for i in range(m):
            row_sum = 0
            for j in range(n):
                cols[j] += grid[i][j]
                row_sum += cols[j]

                if row_sum <= k:
                    ans += 1
            
        return ans