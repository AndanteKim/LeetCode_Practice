class Solution:
    def manhattan_distance(self, row: int, col: int, target: Tuple[int, int]) -> int:
        return target[0] - row + target[1] - col
    
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        rows, cols = len(grid), len(grid[0])
        target = (rows - 1, cols - 1)
        
        state = (0, 0, k)
        queue = [(self.manhattan_distance(0, 0, target), 0, state)]
        seen = set([state])
        
        while queue:
            estimation, steps, (row, col, remain_eliminations) = heappop(queue)
            
            remain_min_distance = estimation - steps
            if remain_min_distance <= remain_eliminations:
                return estimation
            
            for new_row, new_col in [(row, col + 1), (row + 1, col), (row, col - 1), (row - 1, col)]:
                if (0 <= new_row < rows) and (0 <= new_col < cols):
                    new_eliminations = remain_eliminations - grid[new_row][new_col]
                    new_state = (new_row, new_col, new_eliminations)
                    
                    if new_eliminations >= 0 and new_state not in seen:
                        seen.add(new_state)
                        new_estimation = self.manhattan_distance(new_row, new_col, target) + steps + 1
                        heappush(queue, (new_estimation, steps + 1, new_state))
        return -1