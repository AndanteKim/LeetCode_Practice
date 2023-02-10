class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        
        rows, cols = len(grid), len(grid[0])
        
        MAX_DISTANCE = rows + cols + 1
        
        dist = [[MAX_DISTANCE for __ in range(cols)] for _ in range(rows)]
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]:
                    dist[i][j] = 0
                else:
                    dist[i][j] = min(dist[i][j], min(dist[i-1][j] + 1 if i > 0 else MAX_DISTANCE, dist[i][j-1] + 1 if j > 0 else MAX_DISTANCE))
                    
        ans = float('-inf')
        
        for i in range(rows-1, -1, -1):
            for j in range(cols - 1, -1, -1):
                dist[i][j] = min(dist[i][j], min(dist[i+1][j] + 1 if i < rows - 1 else MAX_DISTANCE, dist[i][j+1] + 1 if j < cols - 1 else MAX_DISTANCE))
                ans = max(ans, dist[i][j])
        
        return -1 if (ans == 0 or ans == MAX_DISTANCE) else ans