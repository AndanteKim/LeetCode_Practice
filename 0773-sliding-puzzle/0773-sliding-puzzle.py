class Solution:
    # Direction map for zero's possible moves in a 1D representation of the 2x3 board
    directions = [
        [1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]
    ]
    
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        # Helper method to swap characters at indices i and j in the string
        def _swap(i: int, j: int, s: str) -> str:
            s = list(s)
            s[i], s[j] = s[j], s[i]
            return "".join(s)
        
        target, start_state = "123450", "".join([str(num) for row in board for num in row])
        
        # To store visited states
        visited, moves = set(), 0
        queue = deque([start_state])
        visited.add(start_state)
        
        # BFS to find the minimum number of moves
        while queue:
            size = len(queue)
            for _ in range(size):
                curr_state = queue.popleft()
                
                # Check if we reached the target solved state
                if curr_state == target:
                    return moves
                
                zero_pos = curr_state.index('0')
                for next_pos in self.directions[zero_pos]:
                    next_state = _swap(zero_pos, next_pos, curr_state)
                    
                    # Skip if this state has been visited
                    if next_state in visited:
                        continue
                        
                    # Mark the new state as visited and add it to the queue
                    visited.add(next_state)
                    queue.append(next_state)
                    
            moves += 1
            
        return -1