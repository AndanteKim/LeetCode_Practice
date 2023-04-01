class Solution:
    def valid(self, x: int, y: int, visited: List[List[bool]]) -> bool:
        return 0 <= x < self.m and 0 <= y < self.n and not visited[x][y] and self.grid[x][y] == 1
    
    def dfs(self, x: int, y: int, visited: List[List[bool]]) -> int:
        if not self.valid(x, y, visited):
            return 0
        visited[x][y] = True
        return 1 + self.dfs(x + 1, y, visited)\
                 + self.dfs(x - 1, y, visited)\
                 + self.dfs(x, y + 1, visited)\
                 + self.dfs(x, y - 1, visited)
    
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.m, self.n, self.grid = len(grid), len(grid[0]), grid
        visited = [[False] * self.n for _ in range(self.m)]
        ans = 0
        for i in range(self.m):
            for j in range(self.n):
                ans = max(ans, self.dfs(i, j, visited))
        
        return ans