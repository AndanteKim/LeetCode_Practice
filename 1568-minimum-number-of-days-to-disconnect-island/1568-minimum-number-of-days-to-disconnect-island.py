class Solution:
    # Directions for adjacent cells: right, down, left, up
    directions = ((0, 1), (1, 0), (0, -1), (-1, 0))
    
    def minDays(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ap_info = {"has_articulation_point" : False, "time" : 0}
        land_cells, island_count = 0, 0
        
        # Arrays to store information for each cell
        # Time when a cell is first discovered
        discovery_time = [[-1] * n for _ in range(m)]
        # Lowest discovery time reachable from the subtree rooted at this cell
        lowest_reachable = [[-1] * n for _ in range(m)]
        # Parent of each cell in DFS tree
        parent_cell = [[-1] * n for _ in range(m)]
        
        def _find_articulation_points(row: int, col: int) -> None:
            discovery_time[row][col] = ap_info["time"]
            ap_info["time"] += 1
            lowest_reachable[row][col] = discovery_time[row][col]
            children = 0
            
            # Explore all adjacent cells
            for dr, dc in self.directions:
                new_r = row + dr
                new_c = col + dc
                if 0 <= new_r < m and 0 <= new_c < n and grid[new_r][new_c]:
                    if discovery_time[new_r][new_c] == -1:
                        children += 1
                        
                        # Set parent
                        parent_cell[new_r][new_c] = row * n + col
                        _find_articulation_points(new_r, new_c)
                        
                        # Update the lowest reachable time
                        lowest_reachable[row][col] = min(lowest_reachable[row][col],\
                                                        lowest_reachable[new_r][new_c])
                        
                        # Check for articulation point condition
                        if lowest_reachable[new_r][new_c] >= discovery_time[row][col]\
                        and parent_cell[row][col] != -1:
                            ap_info["has_articulation_point"] = True
                            
                    elif new_r * n + new_c != parent_cell[row][col]:
                        # Update the lowest reachable time for back edge
                        lowest_reachable[row][col] = min(
                            lowest_reachable[row][col],\
                            discovery_time[new_r][new_c]
                        )
                        
            # Root of DFS tree is an articulation point if it has more than one child
            if parent_cell[row][col] == -1 and children > 1:
                ap_info["has_articulation_point"] = True
                
        # Traverse the grid to find islands and articulation points
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    land_cells += 1
                    
                    # If not yet visited
                    if discovery_time[i][j] == -1:
                        # Start DFS for a new island
                        _find_articulation_points(i, j)
                        island_count += 1
                        
        # Determine the minimum number of days to disconnect the grid
        if island_count == 0 or island_count >= 2:
            return 0    # Already disconnected or no land
        
        if land_cells == 1:
            return 1    # Only one land cell
        
        if ap_info["has_articulation_point"]:
            return 1    # An articulation point exists
        return 2    # Need to remove any two land cells
        