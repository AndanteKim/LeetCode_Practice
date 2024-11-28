class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        def is_valid(x: int, y: int) -> bool:
            return 0 <= x < m and 0 <= y < n
        
        m, n = len(grid), len(grid[0])
        visited = [[float('inf')] * n for _ in range(m)]
        pq = [(0, 0, 0)]
        
        while pq:
            min_remove, i, j = heappop(pq)
            
            if min_remove >= visited[i][j]:
                continue
            
            if i == m - 1 and j == n - 1:
                return min_remove
            
            visited[i][j] = min_remove
            
            for di, dj in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                new_i, new_j = i + di, j + dj
                if is_valid(new_i, new_j):
                    heappush(pq, (grid[new_i][new_j] + min_remove, new_i, new_j))
        
        return -1