class Solution:
    def dfs(self, y: int, x: int, visited: List[List[bool]], grid: List[List[int]]) -> bool:
        if x < 0 or x >= self.cols or y < 0 or y >= self.rows:
            return False
        
        if grid[y][x] or visited[y][x]:
            return True
        
        visited[y][x] = True
        isClosed = True
        
        for dy, dx in self.directions:
            new_rows, new_cols = y + dy, x + dx
            if not self.dfs(new_rows, new_cols, visited, grid):
                isClosed = False
        return isClosed
            
        
    def closedIsland(self, grid: List[List[int]]) -> int:
        self.rows, self.cols, ans = len(grid), len(grid[0]), 0
        self.directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        visited = [[False] * self.cols for _ in range(self.rows)]
        
        for y in range(self.rows):
            for x in range(self.cols):
                if grid[y][x] == 0 and not visited[y][x] and self.dfs(y, x, visited, grid):
                    ans += 1
        
        return ans
                    