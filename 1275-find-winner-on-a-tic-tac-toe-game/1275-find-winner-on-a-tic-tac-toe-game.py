class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        A_board, B_board = [[False] * 3 for _ in range(3)], [[False] * 3 for _ in range(3)]
        A_turn = True
        
        for move in moves:
            if A_turn:
                A_board[move[0]][move[1]] = True
                A_turn = False
            else:
                B_board[move[0]][move[1]] = True
                A_turn = True
            
            if (A_board[0][0] and A_board[1][1] and A_board[2][2]) or \
                (A_board[2][0] and A_board[1][1] and A_board[0][2]) or \
                any(sum(A_row) == 3 for A_row in A_board) or \
                any(A_board[0][i] + A_board[1][i] + A_board[2][i] == 3 for i in range(3)):
                    return "A"
                
            if (B_board[0][0] and B_board[1][1] and B_board[2][2]) or \
                (B_board[2][0] and B_board[1][1] and B_board[0][2]) or \
                any(sum(B_row) == 3 for B_row in B_board) or \
                any(B_board[0][i] + B_board[1][i] + B_board[2][i] == 3 for i in range(3)):
                    return "B"
        
        if len(moves) < 9:
            return "Pending"
        
        return "Draw"