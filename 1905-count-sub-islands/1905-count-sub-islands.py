class Solution:
    # Helper method to check if the cell at the position (x, y) in the 'grid'
    # is a land cell.
    def is_cell_land(self, x: int, y: int, grid: List[List[int]]) -> bool:
        return grid[x][y] == 1
    
    # Traverse all cells of island starting at position (x, y) in 'grid2',
    # and check if this island is a sub-island in 'grid1'.
    def is_sub_island(self, x: int, y: int, grid1: List[List[int]], grid2: List[List[int]], visited: List[List[bool]]) -> bool:
        # Traverse on all cells using the depth-first search method.
        is_sub_island = True
        
        # If the current cell isn't a land cell in 'grid1', then the current island can't be a sub-island.
        if not self.is_cell_land(x, y, grid1):
            is_sub_island = False
        
        # Traverse on all adjacent cells
        for new_x, new_y in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
            # If the next cell is inside 'grid2', isn't visited, and is a land cell,
            # then we traverse to the next cell.
            if 0 <= new_x < self.rows and 0 <= new_y < self.cols and not visited[new_x][new_y] and self.is_cell_land(new_x, new_y, grid2):
                # Mark the next cell as visited.
                visited[new_x][new_y] = True
                next_cell_is_part_of_sub_island = self.is_sub_island(new_x, new_y, grid1, grid2, visited)
                is_sub_island &= next_cell_is_part_of_sub_island
                
        return is_sub_island
        
    
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        self.rows, self.cols = len(grid2), len(grid2[0])
        
        visited = [[False] * self.cols for _ in range(self.rows)]
        sub_island_counts = 0
        
        # Iterate over each in 'grid2'.
        for x in range(self.rows):
            for y in range(self.cols):
                # If the cell at the position (x, y) in 'grid2' not visited,
                # is a land cell in 'grid2', and the island starting from this cell is a
                # sub-island in 'grid1',
                # then increment the count of sub-islands.
                if not visited[x][y] and self.is_cell_land(x, y, grid2):
                    visited[x][y] = True
                    
                    if self.is_sub_island(x, y, grid1, grid2, visited):
                        sub_island_counts += 1
                        
        # Return total count of sub-islands
        return sub_island_counts