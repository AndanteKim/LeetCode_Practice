class Solution:
    def dijkstra(self, maze: List[List[int]], start: List[int], distances: List[List[int]]) -> None:
        pq = [(0, start[0], start[1])]
        while pq:
            curr, x, y = heappop(pq)
            if distances[x][y] < curr:
                continue
            
            for dx, dy in (1, 0), (-1, 0), (0, 1), (0, -1):
                new_x, new_y, dist = x + dx, y + dy, 0
                while 0 <= new_x < self.m and 0 <= new_y < self.n and maze[new_x][new_y] == 0:
                    new_x += dx
                    new_y += dy
                    dist += 1
                if distances[x][y] + dist < distances[new_x - dx][new_y - dy]:
                    distances[new_x - dx][new_y - dy] = distances[x][y] + dist
                    heappush(pq, (distances[new_x - dx][new_y - dy], new_x - dx, new_y - dy))                
    
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        self.m, self.n = len(maze), len(maze[0])
        distances = [[float('inf')] * self.n for _ in range(self.m)]
        distances[start[0]][start[1]] = 0
        
        self.dijkstra(maze, start, distances)
        return -1 if distances[destination[0]][destination[1]] == float('inf') else distances[destination[0]][destination[1]]