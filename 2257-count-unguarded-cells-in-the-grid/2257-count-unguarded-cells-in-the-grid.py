class Solution:
    UNGUARDED = 0
    GUARDED = 1
    GUARD = 2
    WALL = 3
    
    # Depth-First Search to mark guarded cells
    def _dfs(self, row: int, col: int, grid: List[List[int]], direction: chr) -> None:
        if row < 0 or row >= self.m or col < 0 or col >= self.n or grid[row][col] == self.WALL \
        or grid[row][col] == self.GUARD:
            return
        
        # Mark cell as guarded
        grid[row][col] = self.GUARDED
        if direction == 'U':
            self._dfs(row - 1, col, grid, 'U')   # Up
        elif direction == 'D':
            self._dfs(row + 1, col, grid, 'D')   # Down
        elif direction == 'L':
            self._dfs(row, col - 1, grid, 'L')   # Left
        else:
            self._dfs(row, col + 1, grid, 'R')   # Right
           
    
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        self.m, self.n = m, n
        grid = [[self.UNGUARDED] * self.n for _ in range(self.m)]
        
        # Mark the guards' positions
        for x, y in guards:
            grid[x][y] = self.GUARD
        
        # Mark the walls' positions
        for x, y in walls:
            grid[x][y] = self.WALL
        
        # Mark cells as guarded by traversing from each guard
        for x, y in guards:
            self._dfs(x - 1, y, grid, 'U')   # Up
            self._dfs(x + 1, y, grid, 'D')   # Down
            self._dfs(x, y - 1, grid, 'L')   # Left
            self._dfs(x, y + 1, grid, 'R')   # Right
        
        # Count ungraded cells
        count = sum(row.count(self.UNGUARDED) for row in grid)
        return count