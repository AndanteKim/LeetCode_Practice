class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        queue = deque()
        directions = ((-1, 0), (1, 0), (0, -1), (0, 1))
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    queue.append((i, j))
        ans = 4 * len(queue)
        while queue:
            x, y = queue.popleft()
            
            for dx, dy in directions:
                if 0 <= x + dx < len(grid) and 0 <= y + dy < len(grid[0]) and grid[x + dx][y + dy] == 1:
                    ans -= 1
                
        return ans
        