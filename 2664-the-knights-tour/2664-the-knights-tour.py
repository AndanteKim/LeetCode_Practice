class Solution:
    def tourOfKnight(self, m: int, n: int, r: int, c: int) -> List[List[int]]:
        # Check if the move is valid
        def valid_move(row: int, col: int) -> bool:
            return 0 <= row < m and 0 <= col < n and board[row][col] == 0
        
        # Implement Warnsdorff's rule: prefer moves with fewer onward moves
        def warnsdorff(row: int, col: int) -> List[int]:
            next_moves = []
            for idx in range(8):
                next_r, next_c = row + moves[idx][0], col + moves[idx][1]
                accessibility_score = sum(valid_move(next_r + move[0], next_c + move[1]) for move in moves)
                next_moves.append((accessibility_score, idx))
                
            # Sort moves based on accessibility (fewer accessible squares first)
            return sorted(next_moves)
        
        def solve(curr_r: int, curr_c: int, move_cnt: int) -> bool:
            # Base case: If all cells have been visited, we've found a solution
            if move_cnt == m * n:
                return True
            
            # Get and sort possible next moves based on Warnsdorff's rule
            next_moves = warnsdorff(curr_r, curr_c)
            
            # Try each possible move
            for _, move_idx in next_moves:
                next_r, next_c = curr_r + moves[move_idx][0], curr_c + moves[move_idx][1]
                
                # Check if the move is valid
                if not valid_move(next_r, next_c):
                    continue
                    
                # Mark the move as visited
                board[next_r][next_c] = move_cnt
                
                # Recursively try to solve from this new position
                if solve(next_r, next_c, move_cnt + 1):
                    return True
                
                # If the move doesn't lead to a solution, backtrack
                board[next_r][next_c] = 0
                
            return False    # No solution found from this position
        
        # Possible knight moves: (row, column) pairs
        moves = [(-1, -2), (-2, -1), (-1, 2), (-2, 1),\
                        (1, -2), (2, -1), (1, 2), (2, 1)]
        
        board = [[0] * n for _ in range(m)]
        board[r][c] = -1
        
        solve(r, c, 1)
        
        # Reset the starting position to 0
        board[r][c] = 0
        
        return board