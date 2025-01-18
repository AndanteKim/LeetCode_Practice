class Solution:
    # Direction lists: right, left, down, up (matching grid values 1, 2, 3, 4)
    _dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        # Min-heap ordered by cost. Each element is (cost, row, col)
        pq = [(0, 0, 0)]    # Using list as heap, elements are tuples
        min_cost = [[float('inf')] * n for _ in range(m)]
        min_cost[0][0] = 0

        while pq:
            cost, row, col = heappop(pq)

            # Skip if we've found a better path to this cell
            if min_cost[row][col] != cost:
                continue
            
            for d, (dr, dc) in enumerate(self._dirs):
                new_r, new_c = row + dr, col + dc
                
                # Check if new position is valid
                if 0 <= new_r < m and 0 <= new_c < n:
                    # Add cost = 1 if we need to change direction
                    new_cost = cost + (d != (grid[row][col] - 1))

                    # Update if we found a better path
                    if min_cost[new_r][new_c] > new_cost:
                        min_cost[new_r][new_c] = new_cost
                        heappush(pq, (new_cost, new_r, new_c))

        return min_cost[m - 1][n - 1]