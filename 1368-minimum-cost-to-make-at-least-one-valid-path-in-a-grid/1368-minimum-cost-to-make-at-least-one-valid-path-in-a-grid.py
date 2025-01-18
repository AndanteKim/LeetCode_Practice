class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        # Initialize all cells with max value
        min_changes = [[float('inf')] * n for _ in range(m)]
        min_changes[0][0] = 0

        while True:
            # Store previous state to check for convergence
            prev_state = [row[:] for row in min_changes]

            # Forward pass: check cells coming from left and top
            for row in range(m):
                for col in range(n):
                    # Check cell above
                    if row > 0:
                        min_changes[row][col] = min(
                            min_changes[row][col],
                            min_changes[row - 1][col]
                            + (0 if grid[row - 1][col] == 3 else 1)
                        )
                    
                    # Check cell to the left
                    if col > 0:
                        min_changes[row][col] = min(
                            min_changes[row][col],
                            min_changes[row][col - 1]
                            + (0 if grid[row][col - 1] == 1 else 1)
                        )

            # Backward pass: check cells coming from right and bottom
            for row in range(m - 1, -1, -1):
                for col in range(n - 1, -1, -1):
                    # Check cell below
                    if row < m - 1:
                        min_changes[row][col] = min(
                            min_changes[row][col],
                            min_changes[row + 1][col]
                            + (0 if grid[row + 1][col] == 4 else 1)
                        )
                    
                    # check cell to the right
                    if col < n - 1:
                        min_changes[row][col] = min(
                            min_changes[row][col],
                            min_changes[row][col + 1]
                            + (0 if grid[row][col + 1] == 2 else 1)
                        )

            # If no changes were made in this iteration, we've found optimal solution
            if min_changes == prev_state:
                break
                            
        return min_changes[m - 1][n - 1]        