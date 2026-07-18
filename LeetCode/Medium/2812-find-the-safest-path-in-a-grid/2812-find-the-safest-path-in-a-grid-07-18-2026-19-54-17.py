class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)

        multi_src_queue = deque()
        # Mark thieves as 0 and empty cells as -1, and push thieves to the queue
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    multi_src_queue.append((i, j))
                    grid[i][j] = 0
                else:
                    grid[i][j] = -1
        
        # Calculate safeness factor for each cell using BFS
        while multi_src_queue:
            sz = len(multi_src_queue)
            while sz > 0:
                x, y = multi_src_queue.popleft()

                for nX, nY in (x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1):
                    val = grid[x][y]

                    if self.is_valid(grid, nX, nY) and grid[nX][nY] == -1:
                        grid[nX][nY] = val + 1
                        multi_src_queue.append((nX, nY))
                sz -= 1

        start, end, ans = 0, 0, -1
        for i in range(n):
            for j in range(n):
                end = max(end, grid[i][j])
        
        while start <= end:
            mid = (start + end) >> 1
            if self.is_valid_safeness(grid, mid):
                ans = mid
                start = mid + 1
            else:
                end = mid - 1

        return ans

    def is_valid(self, grid: List[List[int]], i: int, j: int) -> bool:
        n = len(grid)
        return 0 <= i < n and 0 <= j < n

    def is_valid_safeness(self, grid: List[List[int]], min_safeness: int) -> bool:
        n = len(grid)

        if grid[0][0] < min_safeness or grid[-1][-1] < min_safeness:
            return False
        
        queue = deque([(0, 0)])
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True

        while queue:
            x, y = queue.popleft()
            if x == n - 1 and y == n - 1:
                return True

            for nX, nY in (x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1):
                if self.is_valid(grid, nX, nY) and not visited[nX][nY] and grid[nX][nY] >= min_safeness:
                    visited[nX][nY] = True
                    queue.append((nX, nY))

        return False    # No valid path found.