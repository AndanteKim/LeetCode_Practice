class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        def is_valid(i: int, j: int, visited: List[List[int]]) -> bool:
            return 0 <= i < m and 0 <= j < n and maze[i][j] == 0
        
        m, n = len(maze), len(maze[0])
        queue = deque([(start[0], start[1])])
        visited = [[False] * n for _ in range(m)]

        while queue:
            x, y = queue.popleft()

            if x == destination[0] and y == destination[1]:
                return True
            
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                new_x, new_y, is_moved = x, y, False
                while is_valid(new_x, new_y, visited):
                    new_x += dx
                    new_y += dy
                    is_moved = True

                if is_moved:
                    new_x -= dx
                    new_y -= dy

                if visited[new_x][new_y]:
                    continue 
                visited[new_x][new_y] = True
                queue.append((new_x, new_y))

        return False