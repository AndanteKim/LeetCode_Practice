class Solution:
    def getFood(self, grid: List[List[str]]) -> int:
        # Check if position is within bounds and not blocked
        def _is_valid(i: int, j: int) -> bool:
            return 0 <= i < m and 0 <= j < n and grid[i][j] != 'X'
        
        m, n, queue = len(grid), len(grid[0]), deque([])

        # Possible moves: right, left, up, down
        dirs = [(0, 1), (0, -1), (-1, 0), (1, 0)]

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '*':
                    queue.append((i, j))

        steps = 1

        # BFS traversal
        while queue:
            # Process all cells at current level
            for _ in range(len(queue)):
                r, c = queue.popleft()

                # Try all four directions
                for dr, dc in dirs:
                    new_r, new_c = r + dr, c + dc
                    
                    if _is_valid(new_r, new_c):
                        # Found food
                        if grid[new_r][new_c] == '#':
                            return steps
                        
                        # Mark as visited and add to queue
                        grid[new_r][new_c] = 'X'
                        queue.append((new_r, new_c))
            steps += 1
        
        return -1