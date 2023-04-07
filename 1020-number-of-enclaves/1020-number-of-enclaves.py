class Solution:
    
    def dfs(self, y: int, x: int, visited: List[List[bool]], grid: List[List[int]]) -> bool:
        if y < 0 or y >= self.rows or x < 0 or x >= self.cols:
            return False
        
        if visited[y][x] or not grid[y][x]:
            return True
        
        visited[y][x], isClosed = True, True
        for new_row, new_col in ((y, x + 1), (y, x - 1), (y + 1, x), (y - 1, x)):
            if not self.dfs(new_row, new_col, visited, grid):
                isClosed = False
        self.curr = self.curr + 1 if isClosed else 0
        return isClosed
    
    def numEnclaves(self, grid: List[List[int]]) -> int:
        self.rows, self.cols, ans, self.curr = len(grid), len(grid[0]), 0, 0
        visited = [[False] * self.cols for _ in range(self.rows)]
        
        for y in range(self.rows):
            for x in range(self.cols):
                if grid[y][x] == 1 and not visited[y][x] and self.dfs(y, x, visited, grid):
                    ans += self.curr
                else:
                    self.curr = 0
        return ans