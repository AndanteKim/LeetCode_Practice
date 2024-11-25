class Solution:
    # Direction map for zero's possiblemoves in a flattened 1D array (2 x 3 board)
    directions = [
        [1, 3],
        [0, 2, 4],
        [1, 5],
        [0, 4],
        [1, 3, 5],
        [2, 4]
    ]
    
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        # Helper method to swap characters at indices i and j in the string
        def _swap(s: str, i: int, j: int) -> str:
            s = list(s)
            s[i], s[j] = s[j], s[i]
            return "".join(s)
        
        def _dfs(state: str, zero_pos: int, moves: int) -> None:
            # Skip if this state has been visited with fewer or equal moves
            if state in visited and visited[state] <= moves:
                return
            visited[state] = moves
            
            # Try moving zero to each possible adjacent position
            for next_pos in self.directions[zero_pos]:
                # Swap to generate new state
                new_state = _swap(state, zero_pos, next_pos)
                
                # Recursive DFS with updated state and move count
                _dfs(new_state, next_pos, moves + 1)
        
        # Convert the 2D board into a string representation to use as state
        start_state = "".join(str(num) for row in board for num in row)
        
        # Dictionary to store the minimum moves for each visited state
        visited = dict()
        
        # Start DFS traversal from initial board state
        _dfs(start_state, start_state.index("0"), 0)
        
        # Return the minimum moves required to reach the target state, or -1 if unreachable
        return visited.get("123450", -1)
        