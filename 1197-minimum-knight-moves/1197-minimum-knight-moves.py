class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        directions = ((1, 2), (2, 1), (-1, 2), (-2, 1), (-2, -1), (-1, -2),\
                     (1, -2), (2, -1))
        
        visited, queue = set(), deque([(0, 0, 0)])
        
        while queue:
            curr_x, curr_y, steps = queue.popleft()
            
            if curr_x == x and curr_y == y:
                return steps
            
            for dx, dy in directions:
                new_x, new_y = curr_x + dx, curr_y + dy
                if (new_x, new_y) not in visited:
                    visited.add((new_x, new_y))
                    queue.append((new_x, new_y, steps + 1))
        
                
        return -1