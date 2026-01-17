class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        def is_valid(x: int, y: int) -> bool:
            return 0 <= x < m and 0 <= y < n and maze[x][y] == 0
        
        def dfs(x: int, y: int) -> None:
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                curr_x, curr_y, count = x, y, 0
                
                while (is_valid(curr_x + dx, curr_y + dy)):
                    curr_x += dx
                    curr_y += dy
                    count += 1
                
                if dists[x][y] + count < dists[curr_x][curr_y]:
                    dists[curr_x][curr_y] = dists[x][y] + count
                    dfs(curr_x, curr_y)
                
        m, n = len(maze), len(maze[0])
        dists = [[float('inf')] * n for _ in range(m)]
        dists[start[0]][start[1]] = 0
        dfs(start[0], start[1])
        return -1 if dists[destination[0]][destination[1]] == float('inf') else dists[destination[0]][destination[1]]