class Solution:
    # Helper method to check if the cell at the position (x, y) in the 'grid'
    # is a land cell.
    def is_cell_land(self, x: int, y: int, grid: List[List[int]]) -> bool:
        return grid[x][y] == 1
    
    # Traverse all cells of island starting at position (x, y) in 'grid2',
    # and check this island is a sub-island in 'grid1'.
    def is_sub_island(self, x: int, y: int, grid1: List[List[int]], grid2: List[List[int]], visited: List[List[bool]]) -> bool:
        is_sub_island = True
        
        # Push the starting cell in the queue and mark it as visited.
        queue = deque([(x, y)])
        visited[x][y] = True
        
        # Traverse on all cells using the bread-first search method.
        while queue:
            curr_x, curr_y = queue.popleft()
            
            # If the current position cell isn't a land cell in 'grid1',
            # then the current island can't be a sub-island.
            if not self.is_cell_land(curr_x, curr_y, grid1):
                is_sub_island = False
            
            for dx, dy in self.directions:
                next_x, next_y = curr_x + dx, curr_y + dy
                
                # If the next cell is inside 'grid2', is never visited and
                # is a land cell, then we traverse to the next cell.
                if 0 <= next_x < self.m and 0 <= next_y < self.n and not visited[next_x][next_y] and \
                self.is_cell_land(next_x, next_y, grid2):
                    # Push the next cell in the queue and mark it as visited.
                    visited[next_x][next_y] = True
                    queue.append((next_x, next_y))
                    
        return is_sub_island
    
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        self.m, self.n, ans = len(grid2), len(grid2[0]), 0
        
        # Directions in which we can traverse inside the grids
        self.directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        visited = [[False] * self.n for _ in range(self.m)] 
        
        # Iterate on each cell in 'grid2'
        for x in range(self.m):
            for y in range(self.n):
                # If cell at the position (x, y) in the 'grid2' isn't visited,
                # is a land cell in 'grid2', and the island
                # starting from this cell is a sub-island in 'grid1', then we
                # increment the count of sub-islands.
                if not visited[x][y] and self.is_cell_land(x, y, grid2) and\
                self.is_sub_island(x, y, grid1, grid2, visited):
                        ans += 1
        
        # Return total count of sub-islands
        return ans