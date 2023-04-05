class Solution:
    def valid(self, x: int, y:int) -> bool:
        return 0 <= x < self.r and 0 <= y < self.c
    
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        self.r, self.c = len(grid), len(grid[0])
        queue = deque([(0, 0, k, 0)])
        seen = {(0, 0, k)}
        directions = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        
        while queue:
            y, x, remain, steps = queue.popleft()
            if y == self.r - 1 and x == self.c - 1:
                return steps
            
            for dx, dy in directions:
                next_row, next_col = y + dy, x + dx
                
                if self.valid(next_row, next_col):
                    if not grid[next_row][next_col]:
                        if (next_row, next_col, remain) not in seen:
                            queue.append((next_row, next_col, remain, steps + 1))
                            seen.add((next_row, next_col, remain))
                    elif remain and (next_row, next_col, remain - 1) not in seen:
                        seen.add((next_row, next_col, remain - 1))
                        queue.append((next_row, next_col, remain - 1, steps + 1))
        return -1
        