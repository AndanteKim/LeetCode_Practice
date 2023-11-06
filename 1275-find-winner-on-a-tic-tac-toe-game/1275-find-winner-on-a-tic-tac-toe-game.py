class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        
        # Initialize the board, n = 3
        n = 3
        board = [[0] * n for _ in range(n)]
        
        # check if any of 4 winning conditions to see if the current player has won
        def check_row(row: int, player_id: int) -> bool:
            for col in range(n):
                if board[row][col] != player_id:
                    return False
            
            return True
    
        def check_col(col: int, player_id: int) -> bool:
            for row in range(n):
                if board[row][col] != player_id:
                    return False
            return True
        
        def check_diagonal(player_id: int) -> bool:
            for row in range(n):
                if board[row][row] != player_id:
                    return False
            return True
        
        def check_anti_diagonal(player_id: int) -> bool:
            for row in range(n):
                if board[row][n - 1 - row] != player_id:
                    return False
            return True
        
        # start with player_1
        player = 1
        
        for move in moves:
            row, col = move
            board[row][col] = player
            
            # If any of the winninmg conditions is met, return the current player's id
            if check_row(row, player) or check_col(col, player) or \
            (row == col and check_diagonal(player)) or \
            (row + col == n - 1 and check_anti_diagonal(player)):
                return 'A' if player == 1 else 'B'
            
            # If no one wins so far, change to the other player alternatively
            player *= -1
        
        # If all moves are completed and there is no still no result, we shall check if the\
        # grid is full or not. If so, the game ends with draw, otherwise pending
        return "Draw" if len(moves) == n * n else "Pending"