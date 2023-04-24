class Solution:
    def dfs(self, x: int, y: int, rows: int, cols: int, visited: List[List[bool]], grid: List[List[int]]) -> None:
        if x < 0 or x >= rows or y < 0 or y >= cols or visited[x][y] or not grid[x][y]:
            return
        visited[x][y] = True
        
        for new_x, new_y in ((x + 1, y), (x - 1, y), (x, y - 1), (x, y + 1)):
            self.dfs(new_x, new_y, rows, cols, visited, grid)
        return
    
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m, n, ans = len(grid), len(grid[0]), 0
        visited = [[False] * n for _ in range(m)]
        
        for i in range(m):
            if grid[i][0] and not visited[i][0]:
                self.dfs(i, 0, m, n, visited, grid)
            if grid[i][n - 1] and not visited[i][n - 1]:
                self.dfs(i, n - 1, m, n, visited, grid)
        
        for i in range(n):
            if grid[0][i] and not visited[0][i]:
                self.dfs(0, i, m, n, visited, grid)
            if grid[m - 1][i] and not visited[m - 1][i]:
                self.dfs(m - 1, i, m, n, visited, grid)
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] and not visited[i][j]:
                    ans += 1
        return ans
            