class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        def bfs_backtrack(r: int, c: int) -> int:
            queue, visited = deque(), set()
            max_g = 0
            visited.add((r, c))
            queue.append((r, c, grid[r][c], visited))
            
            while queue:
                curr_r, curr_c, curr_g, curr_vis = queue.popleft()
                max_g = max(max_g, curr_g)
                
                # Search for gold in each of the 4 neighbor cells
                for i in range(4):
                    next_r, next_c = curr_r + dirs[i], curr_c + dirs[i + 1]
                    
                    # If the next cell is in the matrix, has gold,
                    # and has not been visited, add it to the queue
                    if 0 <= next_r < m and 0 <= next_c < n and \
                    grid[next_r][next_c] > 0 and \
                    (next_r, next_c) not in curr_vis:
                        curr_vis.add((next_r, next_c))
                        queue.append((next_r, next_c,\
                                     curr_g + grid[next_r][next_c],
                                     curr_vis.copy()))
                        curr_vis.remove((next_r, next_c))
            
            return max_g
        
        
        dirs, m, n = [0, 1, 0, -1, 0], len(grid), len(grid[0])
        
        # Find the total amount of gold in the grid
        total_gold = sum(sum(row) for row in grid)
        
        # Search for the path with the maximum gold starting from each cell
        ans = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] > 0:
                    ans = max(ans, bfs_backtrack(r, c))
                    
                    # If we found a path with the total gold, it's the max gold
                    if ans == total_gold:
                        return total_gold
        return ans
        