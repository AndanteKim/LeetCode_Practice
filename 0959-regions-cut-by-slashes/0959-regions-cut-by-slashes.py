class Solution:
    # Calculate the index of a triangle in the flattened array
    # Each cell is divided into 4 triangles, numbered 0 to 3 clockwise from the top
    def _get_triangle_index(self, grid_sz: int, row: int, col: int, triangle_num: int) -> int:
        return (grid_sz * row + col) * 4 + triangle_num

    # Union two triangles and return 1 if they were not already connected, 0 otherwise
    def _union_triangles(self, parent_arr: List[int], x: int, y: int) -> int:
        parent_x = self._find_parent(parent_arr, x)
        parent_y = self._find_parent(parent_arr, y)
        
        if parent_x != parent_y:
            parent_arr[parent_x] = parent_y
            return 1    # Regions were merged, so count decreases by 1
        return 0    # Regions were already connected
    
    # Find the parent (root) of a set.
    def _find_parent(self, parent_arr: List[int], x: int) -> int:
        if parent_arr[x] == -1:
            return x
        
        parent_arr[x] = self._find_parent(parent_arr, parent_arr[x])
        return parent_arr[x]
    
    def regionsBySlashes(self, grid: List[str]) -> int:
        grid_sz = len(grid)
        total_triangles = grid_sz * grid_sz * 4
        parent_arr = [-1] * total_triangles
        
        # Initially, each small triangle is a separate region
        ans = total_triangles
        
        for row in range(grid_sz):
            for col in range(grid_sz):
                # Connect with the cell above
                if row > 0:
                    ans -= self._union_triangles(parent_arr, \
                                                 self._get_triangle_index(grid_sz, row - 1, col, 2),\
                                                 self._get_triangle_index(grid_sz, row, col, 0)\
                                                )
                
                # Connect with the cell to the left
                if col > 0:
                    ans -= self._union_triangles(parent_arr, \
                                                self._get_triangle_index(grid_sz, row, col - 1, 1),\
                                                self._get_triangle_index(grid_sz, row, col, 3)\
                                                )
                    
                # If not '/', connect triangles 0-1 and 2-3
                if grid[row][col] != "/":
                    ans -= self._union_triangles(
                        parent_arr,\
                        self._get_triangle_index(grid_sz, row, col, 0),\
                        self._get_triangle_index(grid_sz, row, col, 1)\
                    )
                    
                    ans -= self._union_triangles(
                        parent_arr,\
                        self._get_triangle_index(grid_sz, row, col, 2),\
                        self._get_triangle_index(grid_sz, row, col, 3)\
                    )
                    
                # If not '\', connect triangles 0-3 and 1-2
                if grid[row][col] != '\\':
                    ans -= self._union_triangles(parent_arr, \
                                                 self._get_triangle_index(grid_sz, row, col, 0),\
                                                 self._get_triangle_index(grid_sz, row, col, 3)
                                                )
                    ans -= self._union_triangles(parent_arr, \
                                                 self._get_triangle_index(grid_sz, row, col, 2),\
                                                 self._get_triangle_index(grid_sz, row, col, 1))
                    
        return ans