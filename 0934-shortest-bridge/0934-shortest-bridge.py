class Solution:
    def dfs(self, x: int, y: int, bfs_queue: List[int], grid: List[List[int]]) -> None:
        grid[x][y] = 2
        bfs_queue.append((x, y))
            
        for cur_x, cur_y in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
            if 0 <= cur_x < self.n and 0 <= cur_y < self.n and grid[cur_x][cur_y] == 1:
                self.dfs(cur_x, cur_y, bfs_queue, grid)
    
    def shortestBridge(self, grid: List[List[int]]) -> int:
        self.n = len(grid)
        first_x, first_y = -1, -1
        
        for i in range(self.n):
            for j in range(self.n):
                if grid[i][j]:
                    first_x, first_y = i, j
                    break
            
        bfs_queue = []
        self.dfs(first_x, first_y, bfs_queue, grid)
        
        dist = 0
        
        while bfs_queue:
            new_bfs = []
            
            for x, y in bfs_queue:
                for cur_x, cur_y in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
                    if 0 <= cur_x < self.n and 0 <= cur_y < self.n:
                        if grid[cur_x][cur_y] == 1:
                            return dist
                        elif grid[cur_x][cur_y] == 0:
                            new_bfs.append((cur_x, cur_y))
                            grid[cur_x][cur_y] = -1
            
            bfs_queue = new_bfs
            dist += 1