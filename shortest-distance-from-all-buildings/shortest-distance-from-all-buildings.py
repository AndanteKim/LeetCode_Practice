class Solution:
    def bfs(self, grid: List[List[int]], distances: List[List[List[int]]], row: int, col: int) -> None:
        queue = deque([(row, col)])
        visited = [[False] * self.cols for _ in range(self.rows)]
        visited[row][col] = True
        steps = 0
        
        while queue:
            for _ in range(len(queue), 0, -1):
                x, y = queue.popleft()
                if grid[x][y] == 0:
                    distances[x][y][0] += steps
                    distances[x][y][1] += 1
                
                for next_row, next_col in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                    if 0 <= next_row < self.rows and 0 <= next_col < self.cols:
                        if not visited[next_row][next_col] and grid[next_row][next_col] == 0:
                            visited[next_row][next_col] = True
                            queue.append((next_row, next_col))
            steps += 1
    
    def shortestDistance(self, grid: List[List[int]]) -> int:
        minDist, self.rows, self.cols, totalHouses = float('inf'), len(grid), len(grid[0]), 0
        distances = [[[0, 0] for __ in range(self.cols)] for _ in range(self.rows)]
        
        for row in range(self.rows):
            for col in range(self.cols):
                if grid[row][col] == 1:
                    totalHouses += 1
                    self.bfs(grid, distances, row, col)
        
        for row in range(self.rows):
            for col in range(self.cols):
                if distances[row][col][1] == totalHouses:
                    minDist = min(minDist, distances[row][col][0])

        if minDist == float('inf'):
            return -1
        
        return minDist