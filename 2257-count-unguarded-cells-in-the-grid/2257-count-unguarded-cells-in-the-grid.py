class Solution:
    UNGUARDED = 0
    GUARDED = 1
    GUARD = 2
    WALL = 3
    
    def _mark_guarded(self, row: int, col: int, grid: List[List[int]]) -> None:
        # Traverse upwards
        for r in range(row - 1, -1, -1):
            if grid[r][col] == self.WALL or grid[r][col] == self.GUARD:
                break
            grid[r][col] = self.GUARDED
            
        # Traverse downwards
        for r in range(row + 1, len(grid)):
            if grid[r][col] == self.WALL or grid[r][col] == self.GUARD:
                break
            grid[r][col] = self.GUARDED
            
        # Traverse leftwards
        for c in range(col - 1, -1, -1):
            if grid[row][c] == self.WALL or grid[row][c] == self.GUARD:
                break
            grid[row][c] = self.GUARDED
            
        # Traverse rightwards
        for c in range(col + 1, len(grid[0])):
            if grid[row][c] == self.WALL or grid[row][c] == self.GUARD:
                break
            grid[row][c] = self.GUARDED
    
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[self.UNGUARDED] * n for _ in range(m)]
        
        # Mark guards' positions
        for x, y in guards:
            grid[x][y] = self.GUARD
            
        # Mark walls' positions
        for x, y in walls:
            grid[x][y] = self.WALL
            
        # Mark cells as guarded by traversing from each guard
        for x, y in guards:
            self._mark_guarded(x, y, grid)
        
        # Count unguarded cells
        count = 0
        for row in grid:
            for cell in row:
                if cell == self.UNGUARDED:
                    count += 1
        
        return count