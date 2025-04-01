class Solution:
    def bfs(self, grid: List[List[int]], row: int, col: int, total_houses: int) -> int:
        dists, houses_reached = 0, 0

        # Queue to do a bfs, starting from (r, c) cell
        q = deque([(row, col)])

        # Keep track of visited cells
        visited = [[False] * self.n for _ in range(self.m)]
        visited[row][col], steps = True, 0

        while q and houses_reached != total_houses:
            for i in range(len(q), 0, -1):
                r, c = q.popleft()

                # If this cell is a house, then add the distance from the source to this cell
                # and we go past from this cell.
                if grid[r][c] == 1:
                    dists += steps
                    houses_reached += 1
                    continue
                
                # This cell was an empty cell, hence traverse the next cells which isn't a blockage.
                for dr, dc in (-1, 0), (1, 0), (0, -1), (0, 1):
                    next_r, next_c = r + dr, c + dc
                    if 0 <= next_r < self.m and 0 <= next_c < self.n \
                    and not visited[next_r][next_c] and grid[next_r][next_c] != 2:
                        visited[next_r][next_c] = True
                        q.append((next_r, next_c))
            
            # After traversing one level cells, increment the steps by 1 to reach to next level.
            steps += 1
        
        # If we didn't reach all houses, then any cell visited also cannot reach all houses.
        # Set all cells visited to 2, so we don't check them againb and return float('inf').
        if houses_reached != total_houses:
            for r in range(self.m):
                for c in range(self.n):
                    if grid[r][c] == 0 and visited[r][c]:
                        grid[r][c] = 2
            
            return float('inf')
        
        # If we have reached all houses then return the total distance calculated
        return dists
    
    def shortestDistance(self, grid: List[List[int]]) -> int:
        ans, self.m, self.n = float('inf'), len(grid), len(grid[0])
        total_houses = 0

        for row in range(self.m):
            for col in range(self.n):
                if grid[row][col] == 1:
                    total_houses += 1
    
        # Find the min distance sum for each empty cell.
        for row in range(self.m):
            for col in range(self.n):
                if grid[row][col] == 0:
                    ans = min(ans, self.bfs(grid, row, col, total_houses))

        # If it's impossible to reach all houses from any empty cell, then return -1
        return -1 if ans == float('inf') else ans

