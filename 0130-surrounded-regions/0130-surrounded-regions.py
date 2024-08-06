class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return
        
        self.m, self.n = len(board), len(board[0])
        
        # Step 1). retrieve all border cells
        borders = []
        for i in range(self.m):
            borders.append((i, 0))
            borders.append((i, self.n - 1))
        
        for j in range(self.n):
            borders.append((0, j))
            borders.append((self.m - 1, j))
        
        # Step 2). mark the "escaped" cells, with any placeholder, e.g. 'E'
        for r, c in borders:
            self.BFS(board, r, c)
            
        # Step 3). flip the captured cells ('O' -> 'X') and the escaped one ('E' -> 'O')
        for i in range(self.m):
            for j in range(self.n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'  # captured
                    
                elif board[i][j] == 'E':
                    board[i][j] = 'O'   # escaped
        
    def BFS(self, board: List[List[int]], row: int, col: int) -> None:
        queue = deque([(row, col)])
        
        while queue:
            (r, c) = queue.popleft()
            
            if board[r][c] != 'O':
                continue
                
            # Mark this cell as escaped
            board[r][c] = 'E'
            
            # Check its neighbor cells
            if c < self.n - 1:
                queue.append((r, c + 1))
                
            if r < self.m - 1:
                queue.append((r + 1, c))
                
            if c > 0:
                queue.append((r, c - 1))
            
            if r > 0:
                queue.append((r - 1, c))
                