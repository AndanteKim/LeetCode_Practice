class Solution:
    def bfs(self, x: int, y: int, grid: List[List[int]], visited: List[List[bool]]) -> None:
        queue = deque([(x, y)])
        visited[x][y] = True
        
        while queue:
            x, y = queue.popleft()
            
            for new_row, new_col in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                if new_row < 0 or new_row >= self.m or new_col < 0 or new_col >= self.n:
                    continue
                elif grid[new_row][new_col] and not visited[new_row][new_col]:
                    queue.append((new_row, new_col))
                    visited[new_row][new_col] = True
        return
    
    def numEnclaves(self, grid: List[List[int]]) -> int:
        self.m, self.n = len(grid), len(grid[0])
        visited = [[False] * self.n for _ in range(self.m)]
        
        for i in range(self.m):
            if grid[i][0] and not visited[i][0]:
                self.bfs(i, 0, grid, visited)
            if grid[i][self.n - 1] and not visited[i][self.n - 1]:
                self.bfs(i, self.n - 1, grid, visited)
            
        for i in range(self.n):
            if grid[0][i] and not visited[0][i]:
                self.bfs(0, i, grid, visited)
            if grid[self.m - 1][i] and not visited[self.m - 1][i]:
                self.bfs(self.m - 1, i, grid, visited)
        
        ans = 0
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] and not visited[i][j]:
                    ans += 1
        
        return ans