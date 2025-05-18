class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        # Base case
        if len(grid) == 0:
            return 0

        m, n = len(grid), len(grid[0])
        ans, row_hits, col_hits = 0, 0, [0] * n

        for row in range(m):
            for col in range(n):
                # Reset the hits on the row, if necessary.
                if col == 0 or grid[row][col - 1] == 'W':
                    row_hits = 0 
                    for k in range(col, n):
                        if grid[row][k] == 'W':
                            # stop the scan when we hit the wall
                            break
                        elif grid[row][k] == 'E':
                            row_hits += 1
                
                # Reset the hits on the col, if necessary
                if row == 0 or grid[row - 1][col] == 'W':
                    col_hits[col] = 0
                    for k in range(row, m):
                        if grid[k][col] == 'W':
                            # stop the scan when we hit the wall
                            break
                        elif grid[k][col] == 'E':
                            col_hits[col] += 1

                # Count the hits for each empty cell.
                if grid[row][col] == '0':
                    total_hits = row_hits + col_hits[col]
                    ans = max(ans, total_hits)
        
        return ans