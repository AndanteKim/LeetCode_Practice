class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        multi_src_queue = deque()

        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    multi_src_queue.append((i, j))
                    grid[i][j] = 0
                else:
                    grid[i][j] = -1

        while multi_src_queue:
            sz = len(multi_src_queue)
            while sz > 0:
                x, y = multi_src_queue.popleft()
                val = grid[x][y]
                for nX, nY in (x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1):
                    if self.is_valid(grid, nX, nY) and grid[nX][nY] == -1:
                        grid[nX][nY] = val + 1
                        multi_src_queue.append((nX, nY))
                sz -= 1
        
        # (Maximum_safeness_till_now, x-coords, y-coords)
        pq = [(-grid[0][0], 0, 0)]
        grid[0][0] = -1     # Mark the source cell as visited

        while pq:
            safeness, x, y = heappop(pq)

            if x == n - 1 and y == n - 1:
                return -safeness
            
            for nX, nY in (x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1):
                if self.is_valid(grid, nX, nY) and grid[nX][nY] != -1:
                    heappush(pq, (-min(-safeness, grid[nX][nY]), nX, nY))
                    grid[nX][nY] = -1
        
        return -1

    def is_valid(self, grid: List[List[int]], i: int, j: int) -> bool:
        n = len(grid)
        return 0 <= i < n and 0 <= j < n
