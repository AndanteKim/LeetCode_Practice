class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        grid_sz = len(grid)
        
        # Create a 3x3 matrix for each cell in the original grid
        expanded_grid = [[0] * (grid_sz * 3) for _ in range(grid_sz * 3)]
        
        # Populate the expanded grid based on the original grid
        # 1 represents a barrier in the expanded grid
        for i in range(grid_sz):
            for j in range(grid_sz):
                base_row = i * 3
                base_col = j * 3
                
                # Check the character in the original grid
                if grid[i][j] == "\\":
                    # Mark diagonal for backslash
                    expanded_grid[base_row][base_col] = 1
                    expanded_grid[base_row + 1][base_col + 1] = 1
                    expanded_grid[base_row + 2][base_col + 2] = 1
                    
                elif grid[i][j] == '/':
                    # Mark diagonal for forward slash
                    expanded_grid[base_row][base_col + 2] = 1
                    expanded_grid[base_row + 1][base_col + 1] = 1
                    expanded_grid[base_row + 2][base_col] = 1
                    
        ans = 0
        # Count regions using flood fill
        for i in range(grid_sz * 3):
            for j in range(grid_sz * 3):
                # If we find an unvisited cell (0), it's a new region
                if expanded_grid[i][j] == 0:
                    # Fill that region
                    self._flood_fill(expanded_grid, i, j)
                    ans += 1
                    
        return ans
    
    # Flood fill algorithm to mark all cells in a region
    def _flood_fill(self, expanded_grid: List[List[int]], row: int, col: int) -> None:
        queue = deque([(row, col)])
        expanded_grid[row][col] = 1
        
        while queue:
            r, c = queue.popleft()
            # Check all four directions from the current cell
            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                new_r, new_c = r + dr, c + dc
                
                # If the new cell is valid and unvisited, mark it and add to queue
                if self._is_valid(expanded_grid, new_r, new_c):
                    expanded_grid[new_r][new_c] = 1
                    queue.append((new_r, new_c))
                    
    # Check if a cell is within bounds and unvisited
    def _is_valid(Self, expanded_grid: List[List[int]], row: int, col: int) -> bool:
        n = len(expanded_grid)
        return (row >= 0 and col >= 0 and row < n and col < n and expanded_grid[row][col] == 0)
        