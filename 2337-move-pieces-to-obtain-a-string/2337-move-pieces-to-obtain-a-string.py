class Solution:
    def canChange(self, start: str, target: str) -> bool:
        # Queue to store characters and indices from both strings
        # Record non-underscore characters and their indices
        start_queue, target_queue = deque([(i, c) for i, c in enumerate(start) if c != '_']), deque([(i, c) for i, c in enumerate(target) if c != '_'])
        
        # If number of pieces don't match, return False
        if len(start_queue) != len(target_queue):
            return False
        
        # Compare each piece's type and position
        while start_queue:
            s_i, s_c = start_queue.popleft()
            t_i, t_c = target_queue.popleft()
            
            # Check character match and movement rules
            if s_c != t_c or (s_c == 'L' and s_i < t_i) or (s_c == 'R' and s_i > t_i):
                return False
        
        return True
        