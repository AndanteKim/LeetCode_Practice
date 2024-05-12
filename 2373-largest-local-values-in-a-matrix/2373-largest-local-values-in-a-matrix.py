class Solution:
    # Return the maximum values in the 3 x 3 matrix with top-left as (x, y).
    def find_max(self, grid: List[List[int]], x: int, y: int) -> int:
        max_elem = 0
        for i in range(x, x + 3):
            for j in range(y, y + 3):
                max_elem = max(max_elem, grid[i][j])
        
        return max_elem
    
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        max_local = [[0] * (n - 2) for _ in range(n - 2)]
        
        for i in range(n - 2):
            for j in range(n - 2):
                max_local[i][j] = self.find_max(grid, i, j)
                
        return max_local
        