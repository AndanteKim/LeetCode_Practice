class Solution:
    def sumRemoteness(self, grid: List[List[int]]) -> int:
        # DFS to find sum and count of all cells reachable from (row, col)
        def _dfs(row: int, col: int, arr: List[int]) -> None:
            arr[0] += grid[row][col]    # Add current cell value to sum
            arr[1] += 1     # Increment reachable cells count
            grid[row][col] = -1     # Mark as visited

            # Explore all 4 directions
            for dr, dc in dirs:
                new_r, new_c = row + dr, col + dc
                if _is_valid(new_r, new_c):
                    _dfs(new_r, new_c, arr)
        
        # Checks if cell (row, col) is within grid bounds and not blocked/visited
        def _is_valid(row: int, col: int) -> bool:
            return 0 <= row < n and 0 <= col < n and grid[row][col] > 0

        n = len(grid)
        
        # Calculate total sum of all non-blocked cells
        total = sum(val for row in grid for val in row if val != -1)

        # Direction arrays for moving up, down, left, right
        dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))

        # Calculate remoteness for each non-blocked cell
        res = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] > 0:
                    # arr[0] = sum of reachable cells
                    # arr[1] = count of reachable cells
                    arr = [0, 0]
                    _dfs(i, j, arr)
                    res += (total - arr[0]) * arr[1]
        
        return res