class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        first_x, first_y = -1, -1
        
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    first_x, first_y = i, j
                    break
            
        def dfs(x, y):
            grid[x][y] = 2
            bfs_queue.append((x, y))
            
            for cur_x, cur_y in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
                if 0 <= cur_x < n and 0 <= cur_y < n and grid[cur_x][cur_y] == 1:
                    dfs(cur_x, cur_y)
        
        bfs_queue = []
        dfs(first_x, first_y)
        
        dist = 0
        
        while bfs_queue:
            new_bfs = []
            
            for x, y in bfs_queue:
                for cur_x, cur_y in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
                    if 0 <= cur_x < n and 0 <= cur_y < n:
                        if grid[cur_x][cur_y] == 1:
                            return dist
                        elif grid[cur_x][cur_y] == 0:
                            new_bfs.append((cur_x, cur_y))
                            grid[cur_x][cur_y] = -1
            
            bfs_queue = new_bfs
            dist += 1