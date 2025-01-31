class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        def is_valid(row: int, col: int) -> bool:
            return 0 <= row < m and 0 <= col < n and grid[row][col] == 1
        
        def explore_island(island_id: int, row: int, col: int) -> int:
            if not is_valid(row, col):
                return 0

            grid[row][col] = island_id

            return 1 + (explore_island(island_id, row + 1, col)\
            + explore_island(island_id, row - 1, col)\
            + explore_island(island_id, row, col + 1)\
            + explore_island(island_id, row, col - 1)\
            )

        island_sizes, island_id = dict(), 2
        m, n = len(grid), len(grid[0])
        
        # Step 1: Mark all islands and calculate their sizes
        for row in range(m):
            for col in range(n):
                if grid[row][col] == 1:
                    island_sizes[island_id] = explore_island(island_id, row, col)
                    island_id += 1

        # If there are no islands, return 1
        if not island_sizes:
            return 1

        # If the entire grid is one island, return its size or size +
        if len(island_sizes) == 1:
            island_id -= 1
            return island_sizes[island_id] if island_sizes[island_id] == m * n else island_sizes[island_id] + 1
        
        max_island_size = 1

        # Step 2: Try converting every 0 to 1 and calculate the resulting island size
        for row in range(m):
            for col in range(n):
                if grid[row][col] == 0:
                    curr_island_size = 1
                    neighboring_islands = set()

                    # Check down
                    if row + 1 < m and grid[row + 1][col] > 1:
                        neighboring_islands.add(grid[row + 1][col])

                    # Check up
                    if row - 1 >= 0 and grid[row - 1][col] > 1:
                        neighboring_islands.add(grid[row - 1][col])
                    
                    # Check right
                    if col + 1 < n and grid[row][col + 1] > 1:
                        neighboring_islands.add(grid[row][col + 1])

                    # Check left
                    if col - 1 >= 0 and grid[row][col - 1] > 1:
                        neighboring_islands.add(grid[row][col - 1])
                    
                    # Sum the sizes of all unique neighboring islands
                    for island_id in neighboring_islands:
                        curr_island_size += island_sizes[island_id]
                    max_island_size = max(max_island_size, curr_island_size)

        return max_island_size
        