class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        grid_size = len(grid)
        pts_per_side = grid_size + 1
        total_pts = pts_per_side ** 2
        
        # Initialize disjoint set data structure
        parent_arr = [-1] * total_pts
        
        # Connect border points
        for i in range(pts_per_side):
            for j in range(pts_per_side):
                if i == 0 or j == 0 or i == pts_per_side - 1 or j == pts_per_side - 1:
                    pt = i * pts_per_side + j
                    parent_arr[pt] = 0
                    
        # Set the parent of the top-left corner to itself
        parent_arr[0] = -1
        
        # Start with one region (the border)
        ans = 1
        
        # Process each cell in the grid
        for i in range(grid_size):
            for j in range(grid_size):
                # Treat each slash as an edge connecting two points
                if grid[i][j] == '/':
                    top_right = i * pts_per_side + (j + 1) 
                    bottom_left = (i + 1) * pts_per_side + j
                    ans += self._union(parent_arr, top_right, bottom_left)
                    
                elif grid[i][j] == '\\':
                    top_left = i * pts_per_side + j
                    bottom_right = (i + 1) * pts_per_side + (j + 1)
                    ans += self._union(parent_arr, top_left, bottom_right)
                    
        return ans
    
    def _find(self, parent_arr: List[int], node: int) -> int:
        if parent_arr[node] == -1:
            return node
        
        parent_arr[node] = self._find(parent_arr, parent_arr[node])
        return parent_arr[node]
        
    def _union(self, parent_arr: List[int], node1: int, node2: int) -> int:
        parent1 = self._find(parent_arr, node1)
        parent2 = self._find(parent_arr, node2)
        
        if parent1 == parent2:
            return 1    # Nodes are already in the same set, new region formed
        
        parent_arr[parent2] = parent1   # Union the sets
        return 0    # No new region formed