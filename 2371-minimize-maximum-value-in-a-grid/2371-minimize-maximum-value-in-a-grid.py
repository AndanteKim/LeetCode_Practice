class Solution:
    def minScore(self, grid: List[List[int]]) -> List[List[int]]:
        row, col = len(grid), len(grid[0])
        
        # Min-heap to store elements with their values and coordinates
        # Initialize rows and cols arrays to keep track of maximum values assigned
        min_heap, rows, cols = [], [1] * row, [1] * col
        
        # Populate the min-heap with all elements of the grid
        for i in range(row):
            for j in range(col):
                heappush(min_heap, (grid[i][j], i, j))
                
        # Process elements in ascending order of their values
        while min_heap:
            _, i, j = heappop(min_heap)
            
            # Determine the smallest assignable value based on rows and cols constraints
            val = max(rows[i], cols[j])
            grid[i][j] = val
            
            # Update rows and cols arrays with the next possibile value for each row and column
            rows[i], cols[j] = val + 1, val + 1
            
        return grid