class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        direction = [[-1,0], [1,0], [0,-1], [0,1]]
        r, c = len(grid), len(grid[0])
        visited = [[0 for __ in range(c)] for _ in range(r)]
        
        queue = deque([])
        for i in range(r):
            for j in range(c):
                visited[i][j] = grid[i][j]
                if grid[i][j]:
                    queue.append((i, j))
        
        distance = -1
        while queue:
            len_q = len(queue)
            
            while(len_q):
                landCell = queue.popleft()
                for direc in direction:
                    x, y = landCell[0] + direc[0], landCell[1] + direc[1]
                    
                    if (x >= 0 and y >= 0 and x < r and y < c and visited[x][y] == 0):
                        visited[x][y] = 1
                        queue.append((x,y))
                        
                len_q -= 1
            
            distance += 1
            
        return -1 if distance == 0 else distance