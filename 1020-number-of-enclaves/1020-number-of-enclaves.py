class Solution:
    def dfs(self, x: int, y: int, visited: List[List[bool]], grid: List[List[int]]) -> None:
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]):
            return False
        
        if visited[x][y] or grid[x][y] == 0:
            return True
        
        visited[x][y], isClosed = True, True
        for new_x, new_y in ((x + 1, y), (x - 1, y), (x, y - 1), (x, y + 1)):
            if not self.dfs(new_x, new_y, visited, grid):
                isClosed = False
        self.curr = self.curr + 1 if isClosed else 0
        return isClosed
    
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m, n, self.curr = len(grid), len(grid[0]), 0
        visited, ans = [[False] * n for _ in range(m)], 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and not visited[i][j] and self.dfs(i, j, visited, grid):
                    ans += self.curr
                else:
                    self.curr = 0
        
        return ans