class Solution:
    def valid(self, x: int, y: int, grid: List[List[int]], visited: List[List[bool]]) -> bool:
        return 0 <= x < self.m and 0 <= y < self.n and not visited[x][y] and grid[x][y] == 1
    
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.m, self.n, ans = len(grid), len(grid[0]), 0
        visited = [[False] * self.n for _ in range(self.m)]
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] and not visited[i][j]:
                    curr = 0
                    visited[i][j] = True
                    stack = [(i, j)]
                    
                    while stack:
                        x, y = stack.pop()
                        curr += 1
                        for dx, dy in directions:
                            if self.valid(x + dx, y + dy, grid, visited):
                                stack.append((x + dx, y + dy))
                                visited[x + dx][y + dy] = True
                    ans = max(ans, curr)
        return ans
        