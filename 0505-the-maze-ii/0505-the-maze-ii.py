class Solution:
    def min_distance(self, distances: List[List[int]], visited: List[List[bool]]) -> Tuple[int]:
        x, y = -1, -1
        min_val = float('inf')
        
        for i in range(self.m):
            for j in range(self.n):
                if not visited[i][j] and distances[i][j] < min_val:
                    x, y = i, j
                    min_val = distances[i][j]
        return (x, y)
    
    def dijkstra(self, maze: List[List[int]], distances: List[List[int]], visited: List[List[bool]]) -> None:
        while True:
            x, y = self.min_distance(distances, visited)
            if x < 0:
                break
            visited[x][y] = True
            for dx, dy in (1, 0), (-1, 0), (0, 1), (0, -1):
                new_x, new_y, dist = x + dx, y + dy, 0
                while 0 <= new_x < self.m and 0 <= new_y < self.n and maze[new_x][new_y] == 0:
                    new_x += dx
                    new_y += dy
                    dist += 1
                if distances[x][y] + dist < distances[new_x - dx][new_y - dy]:
                    distances[new_x - dx][new_y - dy] = distances[x][y] + dist
    
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        self.m, self.n = len(maze), len(maze[0])
        distances = [[float('inf')] * self.n for _ in range(self.m)]
        visited = [[False] * self.n for _ in range(self.m)]
        
        distances[start[0]][start[1]] = 0
        self.dijkstra(maze, distances, visited)
        return -1 if distances[destination[0]][destination[1]] == float('inf') else distances[destination[0]][destination[1]]