class Solution:
    # Directions for movement: right, left, down, up
    dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        # Helper method to check if the cell is within the grid bounds
        def is_valid(x: int, y: int) -> bool:
            return 0 <= x < m and 0 <= y < n
        
        m, n = len(grid), len(grid[0])
        
        # Distance matrix to store the minimum obstacles removed to reach each cell
        min_obstacles = [[float('inf')] * n for _ in range(m)]
        min_obstacles[0][0] = 0
        
        dq = deque([(0, 0, 0)])     # (obstacles, row, col)
        
        while dq:
            obstacles, x, y = dq.popleft()
            
            # Explore all four possible directions from the current cell
            for dx, dy in self.dirs:
                new_x, new_y = x + dx, y + dy
                
                if is_valid(new_x, new_y) and min_obstacles[new_x][new_y] == float('inf'):
                    if grid[new_x][new_y] == 1:
                        # If it's an obstacle, add 1 to obstacles and push to the back
                        min_obstacles[new_x][new_y] = min_obstacles[x][y] + 1
                        dq.append((obstacles + 1, new_x, new_y))
                    else:
                        # If it's an empty cell, keep the obstacle count and push to the front
                        min_obstacles[new_x][new_y] = obstacles
                        dq.appendleft((obstacles, new_x, new_y))
        
        return min_obstacles[m - 1][n - 1]