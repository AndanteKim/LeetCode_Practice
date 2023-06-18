class Solution:
    def dfs(self, i: int, j: int, dp: List[List[int]], grid: List[List[int]]) -> int:
        if dp[i][j]:
            return dp[i][j]
        
        ans = 1
        dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))
        for di, dj in dirs:
            ii, jj = i + di, j + dj
            if 0 <= ii < self.m and 0 <= jj < self.n and grid[ii][jj] < grid[i][j]:
                ans += self.dfs(ii, jj, dp, grid) % self.mod
        dp[i][j] = ans
        return ans
    
    def countPaths(self, grid: List[List[int]]) -> int:
        self.m, self.n, self.mod = len(grid), len(grid[0]), 10 ** 9 + 7
        
        dp = [[0] * self.n for _ in range(self.m)]
        return sum(self.dfs(i, j, dp, grid) for i in range(self.m) for j in range(self.n)) % self.mod