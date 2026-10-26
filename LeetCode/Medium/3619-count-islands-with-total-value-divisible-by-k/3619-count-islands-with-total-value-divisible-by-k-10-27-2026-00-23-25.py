class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        self.m, self.n, self.k = len(grid), len(grid[0]), k
        ans, self.visited = 0, [[False] * self.n for _ in range(self.m)]

        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] != 0 and not self.visited[i][j]:
                    ans += self.bfs(i, j, grid)
        
        return ans

    def bfs(self, x: int, y: int, grid: List[List[int]]) -> bool:
        val, queue = 0, deque([(x, y)])
        self.visited[x][y] = True

        while queue:
            i, j = queue.popleft()
            val += grid[i][j]

            for new_i, new_j in ((i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)):
                if 0 <= new_i < self.m and 0 <= new_j < self.n and not self.visited[new_i][new_j] and grid[new_i][new_j] != 0:
                    self.visited[new_i][new_j] = True
                    queue.append((new_i, new_j))
        return (val % self.k) == 0