class Solution:
    def is_valid(self, x: int, y: int, maze: List[List[int]]) -> bool:
        return 0 <= x < self.m and 0 <= y < self.n and maze[x][y] == 0
    
    
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        self.m, self.n = len(maze), len(maze[0])
        distances = [[float('inf')] * self.n for _ in range(self.m)]
        distances[start[0]][start[1]] = 0
        queue = deque([(start[0], start[1])])
        while queue:
            x, y = queue.popleft()
            for dx, dy in (1, 0), (-1, 0), (0, 1), (0, -1):
                new_x, new_y = x + dx, y + dy
                dist = 0
                while self.is_valid(new_x, new_y, maze):
                    new_x += dx
                    new_y += dy
                    dist += 1
                
                if distances[x][y] + dist < distances[new_x - dx][new_y - dy]:
                    distances[new_x - dx][new_y - dy] = distances[x][y] + dist
                    queue.append((new_x - dx, new_y - dy))
        
        return -1 if distances[destination[0]][destination[1]] == float('inf') else distances[destination[0]][destination[1]]
                