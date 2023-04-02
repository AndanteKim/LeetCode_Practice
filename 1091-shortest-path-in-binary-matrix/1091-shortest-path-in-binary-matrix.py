class Solution:
    def valid(self, x: int, y: int, grid: List[List[int]], visited: List[List[bool]]):
        return 0 <= x < self.m and 0 <= y < self.n and not grid[x][y] and not visited[x][y]
    
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] == 1:
            return -1
        self.m, self.n = len(grid), len(grid[0])
        visited = [[False] * self.n for _ in range(self.m)]
        queue, directions = deque([(0, 0, 1)]), [(1, 0), (-1, 0), (0, -1),\
                                                (0, 1), (-1, -1), (1, 1),\
                                                (-1, 1), (1, -1)]
        while queue:
            x, y, path = queue.popleft()
            if x == self.m - 1 and y == self.n - 1:
                return path
            
            for dx, dy in directions:
                if self.valid(x + dx, y + dy, grid, visited):
                    visited[x + dx][y + dy] = True
                    queue.append((x + dx, y + dy, path + 1))
            
        return -1
        
        
            