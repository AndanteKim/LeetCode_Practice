class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        rows, cols = len(maze), len(maze[0])
        maze[entrance[0]][entrance[1]] = '+'
        queue = deque([(entrance[0], entrance[1], 0)])
        while queue:
            x, y, steps = queue.popleft()
            
            for new_row, new_col in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
                if 0 <= new_row < rows and 0 <= new_col < cols and maze[new_row][new_col] == '.':
                    if new_row == 0 or new_row == rows - 1 or new_col == 0 or new_col == cols - 1:
                        return steps + 1
                    maze[new_row][new_col] = '+'
                    queue.append((new_row, new_col, steps + 1))
                    
        return -1