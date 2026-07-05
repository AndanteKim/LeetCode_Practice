class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        dists = [[float("inf")] * n for _ in range(m)]

        q = deque([(0, 0)])
        dists[0][0] = grid[0][0]

        while q:
            x, y = q.popleft()

            if x == m - 1 and y == n - 1:
                return True
            
            for nx, ny in (x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1):
                if nx < 0 or ny < 0 or nx >= m or ny >= n:
                    continue
                
                cost = dists[x][y] + grid[nx][ny]

                if cost >= health:
                    continue
                
                if cost < dists[nx][ny]:
                    dists[nx][ny] = cost
                    if grid[nx][ny] == 0:
                        q.appendleft((nx, ny))
                    else:
                        q.append((nx, ny))

        return False