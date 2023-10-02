class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m, n, ans = len(maze), len(maze[0]), float('inf')
        queue = deque([(entrance[0], entrance[1], 0)])
        visited = [[False] * n for _ in range(m)]
        visited[entrance[0]][entrance[1]] = True
        
        while queue:
            x, y, dist = queue.popleft()
            
            if (x == 0 or y == 0 or x == m - 1 or y == n - 1) and dist != 0:
                return dist
                
            for dx, dy in (1, 0), (-1, 0), (0, 1), (0, -1):
                new_x, new_y = x + dx, y + dy
                if 0 <= new_x < m and 0 <= new_y < n and maze[new_x][new_y] == "." and not visited[new_x][new_y]:
                    visited[new_x][new_y] = True
                    queue.append((new_x, new_y, dist + 1))
        
        return -1 if ans == float('inf') else ans