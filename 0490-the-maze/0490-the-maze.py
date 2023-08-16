class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        rows, cols = len(maze), len(maze[0])
        if maze[start[0]][start[1]] == 1:
            return False
        
        queue, directions, visited = deque([(start[0], start[1])]), ((-1, 0), (1, 0), (0, -1), (0, 1)), [[False] * cols for _ in range(rows)]
        while queue:
            x, y = queue.popleft()
            
            if x == destination[0] and y == destination[1]:
                return True
            
            if visited[x][y]:
                continue
            
            visited[x][y] = True
            for dx, dy in directions:
                new_x, new_y = x, y
                while 0 <= new_x + dx < rows and 0 <= new_y + dy < cols and maze[new_x + dx][new_y + dy] == 0:
                    new_x += dx
                    new_y += dy
                    
                if dx:
                    queue.append((new_x, new_y))
                else:
                    queue.append((new_x, new_y))
        
        return False