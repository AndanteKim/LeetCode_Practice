class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        def is_valid(x: int, y: int, visited: List[List[bool]]) -> bool:
            return 0 <= x < n and 0 <= y < n and not visited[x][y]
        
        def is_possible(t: int) -> bool:
            queue, visited = deque([(0, 0)]), [[False] * n for _ in range(n)]
            visited[0][0] = True

            while queue:
                x, y = queue.popleft()

                if x == n - 1 and y == n - 1:
                    return True
                
                for dx, dy in ((0, -1), (0, 1), (-1, 0), (1, 0)):
                    new_x, new_y = x + dx, y + dy

                    if is_valid(new_x, new_y, visited) and grid[new_x][new_y] <= t:
                        visited[new_x][new_y] = True
                        queue.append((new_x, new_y))

            return False
        
        left, n = grid[0][0], len(grid)
        ans, right = 0, n ** 2 + 1
        
        while left <= right:
            mid = (left + right) >> 1

            if is_possible(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans