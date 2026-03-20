class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans = [[0] * (n - k + 1) for _ in range(m - k + 1)]

        for i in range(m - k + 1):
            for j in range(n - k + 1):
                k_grid = []
                for r in range(i, i + k):
                    for c in range(j, j + k):
                        k_grid.append(grid[r][c])
                k_grid.sort()
                min_diff = float('inf')
                for t in range(len(k_grid) - 1):
                    if k_grid[t] == k_grid[t + 1]:
                        continue
                    min_diff = min(min_diff, k_grid[t + 1] - k_grid[t])
                
                if min_diff != float('inf'):
                    ans[i][j] = min_diff
        
        return ans