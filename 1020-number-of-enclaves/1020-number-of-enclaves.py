class Solution:
    def dfs(self, x: int, y: int, rows: int, cols: int, grid: List[List[int]], visited: List[List[bool]]) -> None:
        if x < 0 or x >= rows or y < 0 or y >= cols or not grid[x][y] or visited[x][y]:
            return
        visited[x][y] = True
        directions = ((1, 0), (0, 1), (-1, 0), (0, -1))
        
        for new_row, new_col in ((x + 1, y), (x - 1, y), (x, y - 1), (x, y + 1)):
            self.dfs(new_row, new_col, rows, cols, grid, visited)
        return
    
    def numEnclaves(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        visited = [[False] * cols for _ in range(rows)]
        
        for i in range(0, rows):
            if grid[i][0] == 1 and not visited[i][0]:
                self.dfs(i, 0, rows, cols, grid, visited)
            if grid[i][cols - 1] == 1 and not visited[i][cols - 1]:
                self.dfs(i, cols - 1, rows, cols, grid, visited)
        
        for i in range(0, cols):
            if grid[0][i] == 1 and not visited[0][i]:
                self.dfs(0, i, rows, cols, grid, visited)
            if grid[rows - 1][i] == 1 and not visited[rows - 1][i]:
                self.dfs(rows - 1, i, rows, cols, grid, visited)
        
        ans = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] and not visited[i][j]:
                    ans += 1
        return ans