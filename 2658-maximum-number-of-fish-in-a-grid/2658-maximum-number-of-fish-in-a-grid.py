class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        # Check boundary conditions, water cells, or already visited cells
        def _is_valid(row: int, col: int) -> bool:
            return 0 <= row < m and 0 <= col < n and grid[row][col] > 0 and not visited[row][col]
        
        def _count_fishes(row: int, col: int) -> int:
            if not _is_valid(row, col):
                return 0
            
            total_fish = grid[row][col]
            # Mark the current cell as visited
            visited[row][col] = True

            # Accumulate the fish count from the current cell and its neighbors
            for dr, dc in dirs:
                new_r, new_c = row + dr, col + dc
                total_fish += _count_fishes(new_r, new_c)

            return total_fish
        
        m, n = len(grid), len(grid[0])

        # A 2D list to track visited cells
        visited, dirs = [[False] * n for _ in range(m)], ((1, 0), (-1, 0), (0, 1), (0, -1))
        ans = 0
        
        # Iterate through all cells in the grid
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    # Start a DFS for unvisited land cells (fish available)
                    ans = max(ans, _count_fishes(i, j))

        # Return the maximum fish count food
        return ans