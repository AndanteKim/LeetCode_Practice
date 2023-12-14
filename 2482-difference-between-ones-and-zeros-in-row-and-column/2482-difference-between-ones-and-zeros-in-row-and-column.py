class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        row_ones, col_ones = [0] * m, [0] * n
        
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    row_ones[i] += 1
                    col_ones[j] += 1
        
        ans = [[0] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                ans[i][j] = row_ones[i] + col_ones[j] - (m - row_ones[i]) - (n - col_ones[j])
        return ans
        