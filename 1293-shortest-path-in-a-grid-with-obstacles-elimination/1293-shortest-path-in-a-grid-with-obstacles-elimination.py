class Solution:
    def valid(self, x: int, y: int, available: int) -> bool:
        return 0 <= x < self.r and 0 <= y < self.c and 0 <= available <= self.k
    
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        
        self.r, self.c, self.k = len(grid), len(grid[0]), k
        
        queue, ans = deque([(0,0,0,k)]), float('inf')
        directions = ((1, 0), (0, 1), (-1, 0), (0, -1))
        visited = [[[False] * (k + 1) for __ in range(self.c)] for _ in range(self.r)]
        visited[0][0][k - 1] = True
        
        while queue:
            x, y, dist, available = queue.popleft()
            
            if (x == self.r - 1 and y == self.c - 1):
                ans = min(ans, dist)
            for dx, dy in directions:
                new_rows, new_cols = x + dx, y + dy
                if self.valid(new_rows, new_cols, available):
                    if not grid[new_rows][new_cols]:
                        if not visited[new_rows][new_cols][available]:
                            visited[new_rows][new_cols][available] = True
                            queue.append((new_rows, new_cols, dist + 1, available))
                    elif available and not visited[new_rows][new_cols][available - 1]:
                        visited[new_rows][new_cols][available - 1] = True
                        queue.append((new_rows, new_cols, dist + 1, available - 1))
                        
        return ans if ans != float('inf') else -1