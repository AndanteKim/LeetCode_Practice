class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        # Checks if given cell coordinates are valid and unvisited
        def is_valid(row: int, col: int) -> bool:
            return 0 <= row < rows and 0 <= col < cols and (row, col) not in visited
        
        # If both initial moves require more than 1 second, impossible to proceed
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        
        rows, cols = len(grid), len(grid[0])
        
        # Possible movements: down, up, right, left
        dirs, visited = ((1, 0), (-1, 0), (0, 1), (0, -1)), set()
        
        # Priority queue stores (time, row, col)
        # Ordered by minimum time to reach each cell
        pq = [(grid[0][0], 0, 0)]
        
        while pq:
            time, row, col = heappop(pq)
            
            # Check if reached target
            if row == rows - 1 and col == cols - 1:
                return time
            
            # Skip if cell already visited
            if (row, col) in visited:
                continue
            
            visited.add((row, col))
            
            # Try all four directions
            for dr, dc in dirs:
                next_r, next_c = row + dr, col + dc
                
                if not is_valid(next_r, next_c):
                    continue
                    
                # Calculate the wait time needed to move to next cell
                wait_time = (1 if (grid[next_r][next_c] - time) % 2 == 0 else 0)
                next_time = max(grid[next_r][next_c] + wait_time, time + 1)
                heappush(pq, (next_time, next_r, next_c))
                    
        return -1