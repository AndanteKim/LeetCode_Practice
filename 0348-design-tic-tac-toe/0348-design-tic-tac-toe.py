class TicTacToe:

    def __init__(self, n: int):
        self.n = n
        self.rows, self.cols = [0] * self.n, [0] * self.n
        self.diagonal, self.antiDiagonal = 0, 0

    def move(self, row: int, col: int, player: int) -> int:
        currentPlayer = 1 if player == 1 else -1
        self.rows[row] += currentPlayer
        self.cols[col] += currentPlayer
        
        if row == col:
            self.diagonal += currentPlayer
        
        if col == len(self.cols) - row - 1:
            self.antiDiagonal += currentPlayer
        
        if abs(self.rows[row]) == self.n or abs(self.cols[col]) == self.n or abs(self.diagonal) == self.n or abs(self.antiDiagonal) == self.n:
            return player
        
        return 0


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)