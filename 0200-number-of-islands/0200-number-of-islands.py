class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        queue, rows, cols = deque([]), len(grid), len(grid[0])
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1":
                    queue.append((i, j, True))
        visited, ans = [[False] * cols for _ in range(rows)], 0 
        
        while queue:
            i, j, is_origin = queue.popleft()
            
            if not visited[i][j]:
                visited[i][j] = True
                if j > 0 and grid[i][j-1] == "1":
                    queue.appendleft((i, j - 1, False))
                if i > 0 and grid[i-1][j] == "1":
                    queue.appendleft((i-1, j, False))
                if j < cols - 1 and grid[i][j+1] == "1":
                    queue.appendleft((i, j + 1, False))
                if i < rows - 1 and grid[i+1][j] == "1":
                    queue.appendleft((i+1, j, False))
                if is_origin:
                    ans += 1
                
        return ans