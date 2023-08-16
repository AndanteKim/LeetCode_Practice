class Solution:
    def dfs(self, m: int, n: int, maze: List[List[int]], curr: List[int], destination: List[int], visited: List[List[bool]]) -> bool:
        if visited[curr[0]][curr[1]]:
            return False
        
        if curr[0] == destination[0] and curr[1] == destination[1]:
            return True
        
        visited[curr[0]][curr[1]] = True
        dirX, dirY = [0, 1, 0, -1], [-1, 0, 1, 0]
        
        for i in range(4):
            r, c = curr[0], curr[1]
            
            while 0 <= r and r < m and 0 <= c and c < n and maze[r][c] == 0:
                r += dirX[i]
                c += dirY[i]
            
            if self.dfs(m, n, maze, [r - dirX[i], c - dirY[i]], destination, visited):
                return True
        
        return False
    
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        m, n = len(maze), len(maze[0])
        visited = [[False] * n for _ in range(m)]
        
        return self.dfs(m, n, maze, start, destination, visited)