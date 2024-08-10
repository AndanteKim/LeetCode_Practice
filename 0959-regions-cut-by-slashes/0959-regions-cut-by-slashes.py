class Solution:
    def not_valid(self, expanded_grid: List[List[int]], r: int, c: int) -> bool:
        return r < 0 or r >= self.n or c < 0 or c >= self.n or expanded_grid[r][c]
    
    # flood fill algorithms to fill 0 by DFS
    def flood_fill(self, expanded_grid: List[List[int]], r: int, c: int) -> None:
        if self.not_valid(expanded_grid, r, c):
            return
        
        expanded_grid[r][c] = 1
        for dr,dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            new_r, new_c = r + dr, c + dc
            self.flood_fill(expanded_grid, new_r, new_c)
    
    def regionsBySlashes(self, grid: List[str]) -> int:
        grid_sz = len(grid)
        
        # Create a 3x3 matrix for each cell in the original grid
        expanded_grid = [[0] * (grid_sz * 3) for _ in range(grid_sz * 3)]
        
        # Populate the expanded grid based on the original grid
        # 1 represents a barrier in the expanded grid
        for i in range(grid_sz):
            for j in range(grid_sz):
                base_row, base_col = i * 3, j * 3
                
                # Check the character in the original grid
                if grid[i][j] == '\\':
                    # Mark diagonal for backslash
                    expanded_grid[base_row][base_col] = 1
                    expanded_grid[base_row + 1][base_col + 1] = 1
                    expanded_grid[base_row + 2][base_col + 2] = 1
                    
                elif grid[i][j] == '/':
                    # Mark diagonal for forward slash
                    expanded_grid[base_row + 2][base_col] = 1
                    expanded_grid[base_row + 1][base_col + 1] = 1
                    expanded_grid[base_row][base_col + 2] = 1
                    
        ans, self.n = 0, len(expanded_grid)
        # Count regions using flood fill
        for i in range(self.n):
            for j in range(self.n):
                # If we find an unvisited cell (0), it's a new region
                if expanded_grid[i][j] == 0:
                    # Fill that region
                    self.flood_fill(expanded_grid, i, j)
                    ans += 1
        
        return ans