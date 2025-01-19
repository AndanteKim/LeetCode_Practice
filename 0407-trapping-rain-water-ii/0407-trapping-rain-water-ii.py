class Solution:
    # Class to store the height and coordinates of a cell in the grid
    class Cell:
        def __init__(self, height: int, row: int, col: int):
            self.height = height
            self.row = row
            self.col = col
        
        # Comparision method for the priority queue (min-heap)
        def __lt__(self, other: 'Cell'):
            return self.height < other.height
    
    # Helper function to check if a cell is valid (within grid bounds)
    def _is_valid_cell(self, row: int, col: int) -> bool:
        return 0 <= row < self.m and 0 <= col < self.n

    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        self.m, self.n = len(heightMap), len(heightMap[0])
        d_row, d_col = [0, 0, -1, 1], [-1, 1, 0, 0]
        visited = [[False] * self.n for _ in range(self.m)]

        # Priority queue (min-heap) to process boundary cells in increasing height order
        boundary = []

        # Add the first and last column cells to the boundary and mark them as visited
        for i in range(self.m):
            heappush(boundary, self.Cell(heightMap[i][0], i, 0))
            heappush(boundary, self.Cell(heightMap[i][self.n - 1], i, self.n - 1))
            visited[i][0] = visited[i][self.n - 1] = True

        # Add the first and last row cells to the boundary and mark them as visited
        for i in range(self.n):
            heappush(boundary, self.Cell(heightMap[0][i], 0, i))
            heappush(boundary, self.Cell(heightMap[self.m - 1][i], self.m - 1, i))
            visited[0][i] = visited[self.m - 1][i] = True

        # Initialize the total water volume to 0
        total_water_volume = 0

        # Process cells in the boundary (min-heap will always pop the smallest height)
        while boundary:
            # Pop the cell with the smallest height from the boundary
            curr_cell = heappop(boundary)

            curr_r, curr_c = curr_cell.row, curr_cell.col
            min_boundary_height = curr_cell.height

            # Explore all 4 neighboring cells
            for d in range(4):
                # Calculate the row and column of the neighbor
                next_r, next_c = curr_r + d_row[d], curr_c + d_col[d]

                # Check if the neighbor is within the grid bounds and not yet visited
                if (self._is_valid_cell(next_r, next_c) and not visited[next_r][next_c]):
                    # Get the height of the neighbor cell
                    next_h = heightMap[next_r][next_c]

                    # If the neighbor's height is less than the current boundary height, water can be trapped.
                    if next_h < min_boundary_height:
                        # Add the trapped water volume
                        total_water_volume += min_boundary_height - next_h

                    # Push the neighbor into the boundary with updated height (to prevent water leakage)
                    heappush(boundary, self.Cell(max(next_h, min_boundary_height), next_r, next_c))
                    visited[next_r][next_c] = True

        # Return the total amount of trapped water
        return total_water_volume