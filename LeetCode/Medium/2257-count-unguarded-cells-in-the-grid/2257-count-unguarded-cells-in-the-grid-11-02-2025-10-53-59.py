class Solution:
    UNGUARDED = 0
    GUARDED = 1
    GUARD = 2
    WALL = 3

    def _mark_guarded(self, x: int, y: int, grid: List[List[int]]) -> None:
        # Traverse upwards:
        for r in range(x - 1, -1, -1):
            if grid[r][y] == self.WALL or grid[r][y] == self.GUARD:
                break
            grid[r][y] = self.GUARDED
        
        # Traverse downwards
        for r in range(x + 1, len(grid)):
            if grid[r][y] == self.WALL or grid[r][y] == self.GUARD:
                break
            grid[r][y] = self.GUARDED

        # Traverse leftwards
        for c in range(y - 1, -1, -1):
            if grid[x][c] == self.WALL or grid[x][c] == self.GUARD:
                break
            grid[x][c] = self.GUARDED
        
        # Traverse rightwards
        for c in range(y + 1, len(grid[0])):
            if grid[x][c] == self.WALL or grid[x][c] == self.GUARD:
                break
            grid[x][c] = self.GUARDED
    
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