class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n, m, MOD = len(grid), len(grid[0]), 12345
        ans = [[0] * m for _ in range(n)]
        
        prefix, suffix = 1, 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                ans[i][j] = suffix
                suffix = (suffix * grid[i][j]) % MOD

        for i in range(n):
            for j in range(m):
                ans[i][j] = (ans[i][j] * prefix) % MOD
                prefix = (prefix * grid[i][j]) % MOD

        return ans