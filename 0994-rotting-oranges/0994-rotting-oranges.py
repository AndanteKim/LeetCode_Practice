class Solution:
    def is_valid(self, x: int, y: int, rows: int, cols: int, visited: List[List[int]], grid: List[List[int]]) -> bool:
        if x < 0 or x >= rows or y < 0 or y >= cols or visited[x][y] or grid[x][y] != 1:
            return False
        visited[x][y] = True
        grid[x][y] = 2
        return True
    
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ans, fresh_orange = 0, 0
        rows, cols = len(grid), len(grid[0])
        queue = deque()
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    queue.append((i, j))
                elif grid[i][j] == 1:
                    fresh_orange += 1
        
        visited = [[False] * cols for _ in range(rows)]
        while queue:
            for _ in range(len(queue)):
                x, y = queue.popleft()
                
                for new_x, new_y in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                    if self.is_valid(new_x, new_y, rows, cols, visited, grid):
                        queue.append((new_x, new_y))
                        fresh_orange -= 1
            if queue:
                ans += 1
        
        return ans if fresh_orange == 0 else -1
        
        
        