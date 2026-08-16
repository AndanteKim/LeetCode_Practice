class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self.rows, self.cols = len(matrix), len(matrix[0])
        if self.rows == 0 or self.cols == 0:
            return

        # Initialize 2D bit
        self.bit = [[0] * (self.cols + 1) for _ in range(self.rows + 1)]
        self._build_bit(matrix)
    
    def _lsb(self, n: int) -> int:
        return n & (-n)
        

    def _update_bit(self, r: int, c: int, val: int) -> None:
        i = r
        while i <= self.rows:
            j = c
            while j <= self.cols:
                self.bit[i][j] += val
                j += self._lsb(j)
            i += self._lsb(i)

    def _query_bit(self, r: int, c: int) -> int:
        total = 0
        i = r

        while i > 0:
            j = c
            while j > 0:
                total += self.bit[i][j]
                j -= self._lsb(j)
            i -= self._lsb(i)
        return total

    def _build_bit(self, matrix: List[List[int]]) -> None:
        for i in range(1, self.rows + 1):
            for j in range(1, self.cols + 1):
                val = matrix[i - 1][j - 1]
                self._update_bit(i, j, val)
    
    def update(self, row: int, col: int, val: int) -> None:
        old_val = self.sumRegion(row, col, row, col)

        diff = val - old_val
        self._update_bit(row + 1, col + 1, diff)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        row1 += 1
        col1 += 1
        row2 += 1
        col2 += 1
    
        a = self._query_bit(row2, col2)
        b = self._query_bit(row1 - 1, col1 - 1)
        c = self._query_bit(row2, col1 - 1)
        d = self._query_bit(row1 - 1, col2)

        return (a + b) - (c + d)


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)