class Solution:
    def valid(self, x: int, y: int, r: int, c: int, grid: List[List[int]], visited: List[List[bool]], threshold: int) -> bool:
        return 0 <= x < r and 0 <= y < c and grid[x][y] <= threshold and not visited[x][y]
    
    def feasible(self, grid: List[List[int]], r:int, c: int, threshold: int) -> bool:
        visited = [[False] * c for _ in range(r)]
        queue = deque([(0, 0)])
        directions = ((1, 0), (-1, 0), (0, -1), (0, 1))
        
        while queue:
            x, y = queue.popleft()
            for dx, dy in directions:
                new_x, new_y = x + dx, y + dy
                if self.valid(new_x, new_y, r, c, grid, visited, threshold):
                    visited[new_x][new_y] = True
                    queue.append((new_x, new_y))
        
        return visited[0][0] and visited[r - 1][c - 1]
        
    
    def swimInWater(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        left, right = 0, max(grid[r][c] for r in range(m) for c in range(n))
        
        while left < right:
            mid = (left + right) >> 1
            if self.feasible(grid, m, n, mid):
                right = mid
            else:
                left = mid + 1
        return left