class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        
        total = [[0] * cols for _ in range(rows)]
        emptyLandValue, minDist = 0, float('inf');
        
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1:
                    minDist = float('inf')
                    
                    queue, steps = deque([(row, col)]), 0
                    
                    while queue:
                        steps += 1
                        for _ in range(len(queue), 0, -1):
                            x, y = queue.popleft()
                            
                            for next_row, next_col in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                                if 0 <= next_row < rows and 0 <= next_col < cols and grid[next_row][next_col] == emptyLandValue:
                                    grid[next_row][next_col] -= 1
                                    total[next_row][next_col] += steps
                                    queue.append((next_row, next_col))
                                    minDist = min(minDist, total[next_row][next_col])
                    emptyLandValue -= 1
        return -1 if minDist == float('inf') else minDist