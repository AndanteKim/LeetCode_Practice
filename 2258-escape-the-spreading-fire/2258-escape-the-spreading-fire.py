class Solution:
    def maximumMinutes(self, grid: List[List[int]]) -> int:
        def bfs(queue: List[List[int]], seen: List[List[int]]) -> None:
            for i, j, t in queue:
                if seen[i][j] < inf:
                    continue
                seen[i][j] = t
                for di, dj in d:
                    x, y = i + di, j + dj
                    if 0 <= x < m and 0 <= y < n and seen[x][y] >= inf and t + 1 < grid[x][y]:
                        queue.append([x, y, t + 1])
        
        def die(t: int) -> bool:
            seen = [[inf + 10] * n for _ in range(m)]
            bfs([[0, 0, t]], seen)
            return seen[-1][-1] > grid[-1][-1]
        
        m, n = len(grid), len(grid[0])
        inf, d = 10 ** 10, ((0, 1), (1, 0), (0, -1), (-1, 0))
        fires = [[i, j, 0] for i in range(m) for j in range(n) if grid[i][j] == 1]
        grid = [[inf if col < 2 else -1 for col in row] for row in grid]
        
        bfs(fires, grid)
        grid[-1][-1] += 1
        return bisect_left(range(10 ** 9 + 1), True, key = die) - 1
        
        