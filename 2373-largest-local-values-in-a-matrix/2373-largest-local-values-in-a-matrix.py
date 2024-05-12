class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        ans = [[0] * (n - 2) for _ in range(n - 2)]
        
        for i in range(1, n - 1):
            for j in range(1, n - 1):
                ans[i - 1][j - 1] = grid[i][j]
                for r, c in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1), (i - 1, j - 1), (i - 1, j + 1), \
                (i + 1, j - 1), (i + 1, j + 1):
                    ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[r][c])
                
        return ans        