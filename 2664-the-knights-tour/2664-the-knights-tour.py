class Solution:
    def tourOfKnight(self, m: int, n: int, r: int, c: int) -> List[List[int]]:
        def valid_move(to_row: int, to_col: int) -> bool:
            return 0 <= to_row < m and 0 <= to_col < n and board[to_row][to_col] == 0
        
        def backtrack(curr_r: int, curr_c: int, move_cnt: int) -> bool:
            # Base case: If all cells have been visited, we've found a solution
            if move_cnt == m * n:
                return True
            
            # Try all possible knight moves
            for dr, dc in moves:
                new_r, new_c = curr_r + dr, curr_c + dc
                # Check if the move is valid
                if valid_move(new_r, new_c):
                    board[new_r][new_c] = move_cnt
                    
                    # Recursively try to solve from this new position
                    if backtrack(new_r, new_c, move_cnt + 1):
                        return True
                    
                    # If the move doesn't lead to a solution, backtrack
                    board[new_r][new_c] = 0
                    
            # If no solution is found from the current position
            return False
                    
        # Precompute possible knight moves
        moves = ((2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2))
        board = [[0] * n for _ in range(m)]
        board[r][c] = -1
        
        # Start the recursive solving process
        backtrack(r, c, 1)
        board[r][c] = 0
        
        return board