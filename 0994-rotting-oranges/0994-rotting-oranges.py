class Solution:
    def is_valid(self, x: int, y: int, grid: List[List[int]], visited: List[List[bool]]) -> bool:
        return 0 <= x < len(grid) and 0 <= y < len(grid[0]) and not visited[x][y] and grid[x][y] == 1
    
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue, rows, cols, fresh, ans = deque(), len(grid), len(grid[0]), 0, 0
        visited = [[False] * cols for _ in range(rows)]
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    fresh += 1
                
                if grid[i][j] == 2:
                    queue.append((i, j, 0))
                    
        while queue:
            x, y, days = queue.popleft()
            
            ans = max(ans, days)
            for new_x, new_y in (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1):
                if self.is_valid(new_x, new_y, grid, visited):
                    visited[new_x][new_y] = True
                    grid[new_x][new_y] = 2
                    fresh -= 1
                    queue.append((new_x, new_y, days + 1))
            
        return -1 if fresh > 0 else ans