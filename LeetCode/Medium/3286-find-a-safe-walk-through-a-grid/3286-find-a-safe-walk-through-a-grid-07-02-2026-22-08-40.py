class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])
        dis = [[-1] * n for _ in range(m)]
        
        pq = [(grid[0][0], 0, 0)]   # (cost, x, y)
        while pq:
            val, x, y = heappop(pq)
            if dis[x][y] >= 0:
                continue
            
            dis[x][y] = val
            for new_x, new_y in (x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1):
                if 0 <= new_x < m and 0 <= new_y < n and dis[new_x][new_y] == -1:
                    heappush(pq, (val + grid[new_x][new_y], new_x, new_y))
        
        return dis[m - 1][n - 1] < health
