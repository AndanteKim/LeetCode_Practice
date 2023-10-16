class Solution:
    cache = defaultdict(int)
    def key(self, i: int, j: int) -> int:
        hashed = i ^ (i >> 32)
        return (hashed << 5) - 1 + (j ^ (j >> 32))
    
    
    def get_num(self, row: int, col: int) -> int:
        row_col = self.key(row, col)
        if self.cache[row_col] > 0:
            return self.cache[row_col]
        
        if row == 0 or col == 0 or row == col:
            self.cache[row_col] = 1
            return self.cache[row_col]
        self.cache[row_col] = self.get_num(row - 1, col - 1) + self.get_num(row - 1, col)
        return self.cache[row_col]
    
    def getRow(self, rowIndex: int) -> List[int]:
        ans = []
        
        for i in range(rowIndex + 1):
            ans.append(self.get_num(rowIndex, i))
            
        return ans