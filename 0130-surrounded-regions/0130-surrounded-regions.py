class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board and not board[0]:
            return
        
        self.m, self.n = len(board), len(board[0])
        
        # Step1). retrieve all border cells
        borders = list(product(range(self.m), [0, self.n - 1])) + list(product([0, self.m - 1], range(self.n)))
        
        # Step2). mark the "escaped" cells, with any placeholder, e.g. 'E'
        for row, col in borders:
            self.DFS(board, row, col)
            
        # Step3). flip the captured cells ('O' -> 'X') and the escaped one ('E' -> 'O')
        for i in range(self.m):
            for j in range(self.n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'   # captured
                
                elif board[i][j] == 'E':
                    board[i][j] = 'O'   # escaped
                    
                    
    def DFS(self, board: List[List[int]], row: int, col: int) -> None:
        if (board[row][col] != 'O'):
            return
        board[row][col] = 'E'
        
        if col < self.n - 1:
            self.DFS(board, row, col + 1)
        
        if row < self.m - 1:
            self.DFS(board, row + 1, col)
            
        if col > 0:
            self.DFS(board, row, col - 1)
            
        if row > 0:
            self.DFS(board, row - 1, col)
       