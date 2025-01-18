class Solution:
    # Direction vectors: right, left, down, up (matching grid values 1, 2, 3, 4)
    _dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))

    def minCost(self, grid: List[List[int]]) -> int:
        self.m, self.n = len(grid), len(grid[0])
        
        # Track minimum cost to reach each cell
        min_cost = [[float('inf')] * self.n for _ in range(self.m)]
        
        # Use deque for 0-1 BFS - add zero cost moves to front, cost = 1 to back
        dq, min_cost[0][0] = deque([(0, 0)]), 0

        while dq:
            row, col = dq.popleft()

            # Try all four directions
            for d, (dr, dc) in enumerate(self._dirs):
                new_r, new_c = row + dr, col + dc
                cost = 0 if grid[row][col] == d + 1 else 1

                # If position is valid and we found a better path
                if (self._is_valid(new_r, new_c) 
                and min_cost[row][col] + cost < min_cost[new_r][new_c]):
                    min_cost[new_r][new_c] = min_cost[row][col] + cost
                    # Add to back if cost = 1, front if cost = 0
                    if cost == 1:
                        dq.append((new_r, new_c))
                    else:
                        dq.appendleft((new_r, new_c))
        
        return min_cost[self.m - 1][self.n - 1]
    
    # Check if coordinates are within grid bounds
    def _is_valid(self, row: int, col: int) -> bool:
        return 0 <= row < self.m and 0 <= col < self.n
