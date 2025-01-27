class Solution:
    def sumRemoteness(self, grid: List[List[int]]) -> int:
        def _is_valid(row: int, col: int) -> bool:
            return 0 <= row < n and 0 <= col < n and grid[row][col] > 0
        
        # BFS to find sum and count of all cells reachable from (row, col)
        def _bfs(row: int, col: int, total: int) -> int:
            comp_sum = grid[row][col]   # Sum of values in current component
            comp_size = 1   # Number of cells in component
            grid[row][col] = -1    # Mark as visited

            queue = deque([(row, col)])
            while queue:
                curr_r, curr_c = queue.popleft()
                # Explore all 4 directions
                for dr, dc in dirs:
                    new_r, new_c = curr_r + dr, curr_c + dc

                    if _is_valid(new_r, new_c):
                        queue.append((new_r, new_c))
                        comp_sum += grid[new_r][new_c]
                        comp_size += 1
                        grid[new_r][new_c] = -1    # Mark as visited
            
            # Return remoteness value for this component
            return (total - comp_sum) * comp_size
        
        # Direction arrays for moving up, down, left, right
        dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))
        n = len(grid)

        # Calculate total sum of all non-blocked cells
        total = sum(val for row in grid for val in row if val != -1)

        # Calculate remoteness for each non-blocked cell
        ans = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] > 0:
                    ans += _bfs(i, j, total)

        return ans