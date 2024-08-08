class Solution:
    # All possible single-step moves on the lock pattern grid
    # Each tuple represents a move as (row change, column change)
    SINGLE_STEP_MOVES = [
        # Adjacent moves (right, left, down, up)
        (0, 1), (0, -1), (1, 0), (-1, 0),\
        
        # Diagonal moves
        (1, 1), (-1, 1), (1, -1), (-1, -1),\
        
        # Extended moves (knight-like moves)
        (-2, 1), (-2, -1), (2, 1), (2, -1),\
        (1, -2), (-1, -2), (1, 2), (-1, 2)
    ]
    
    # Moves that require a dot to be visited in between
    # These moves "jump" over a dot, which must have been previously visited
    SKIP_DOT_MOVES = [
        # Straight skip moves (e.g. 1 to 3, 4 to 6)
        (0, 2), (0, -2), (2, 0), (-2, 0),\
        
        # Diagonal skip moves (e.g. 1 to 9, 3 to 7)
        (-2, -2), (2, 2), (2, -2), (-2, 2)\
    ]
    
    
    def numberOfPatterns(self, m: int, n: int) -> int:
        ans = 0
        
        # Start from each of the 9 dots on the grid
        for row in range(3):
            for col in range(3):
                visited = [[False for _ in range(3)] for _ in range(3)]
                
                # Count patterns starting from this dot
                ans += self._count_patterns_from_dot(m, n, 1, row, col, visited)
                
        return ans
    
    def _count_patterns_from_dot(self, m: int, n: int, curr_len: int, curr_r: int, curr_c: int,\
                                 visited: List[List[bool]]) -> int:
        # Base case: If current pattern length exceeds n, stop exploring
        if curr_len > n:
            return 0
        
        valid_patterns = 0
        # If current pattern length is within the valid range, count it
        if curr_len >= m:
            valid_patterns += 1
            
        # Mark current dot as visited
        visited[curr_r][curr_c] = True
        
        # Explore all single-step moves
        for move in self.SINGLE_STEP_MOVES:
            new_r, new_c = curr_r + move[0], curr_c + move[1]
            
            if self._is_valid(new_r, new_c, visited):
                # Recursively count patterns from the new position
                valid_patterns += self._count_patterns_from_dot(m, n, curr_len + 1, new_r, new_c, visited)
                
        # Explore all skip-dot moves
        for move in self.SKIP_DOT_MOVES:
            new_r, new_c = curr_r + move[0], curr_c + move[1]
            
            if self._is_valid(new_r, new_c, visited):
                # Check if the middle dot has been visited
                mid_r = curr_r + (move[0] >> 1)
                mid_c = curr_c + (move[1] >> 1)
                
                if visited[mid_r][mid_c]:
                    # If middle dot is visited, this move is valid
                    valid_patterns += self._count_patterns_from_dot(m, n, curr_len + 1, new_r, new_c, visited)
                    
        # Backtrack: unmark the current dot before returning
        visited[curr_r][curr_c] = False
        return valid_patterns
    
    def _is_valid(self, row: int, col: int, visited: List[List[bool]]) -> bool:
        # A move is valid if it's within the grid and the dot hasn't been visited
        return 0 <= row < 3 and 0 <= col < 3 and not visited[row][col]
   