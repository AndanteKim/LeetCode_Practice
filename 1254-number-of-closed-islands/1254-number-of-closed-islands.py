class Solution:
    def bfs(self, y: int, x: int, visited: List[List[bool]], grid: List[List[int]]) -> bool:
        queue = deque([(y, x)])
        visited[y][x], isClosed = True, True
        
        while queue:
            y, x = queue.popleft()
            for dy, dx in self.directions:
                new_row, new_col = y + dy, x + dx
                if new_row < 0 or new_row >= self.rows or new_col < 0 or new_col >= self.cols:
                    isClosed = False
                elif not grid[new_row][new_col] and not visited[new_row][new_col]:
                    queue.append((new_row, new_col))
                    visited[new_row][new_col] = True
        
        return isClosed
    
    def closedIsland(self, grid: List[List[int]]) -> int:
        self.rows, self.cols, ans = len(grid), len(grid[0]), 0
        self.directions = ((1, 0), (-1, 0), (0, 1), (0, -1))
        visited = [[False] * self.cols for _ in range(self.rows)]
        
        for y in range(self.rows):
            for x in range(self.cols):
                if not grid[y][x] and not visited[y][x] and self.bfs(y, x, visited, grid):
                    ans += 1
        
        return ans
        
        