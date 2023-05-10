class Solution:
    def floorMod(self, x: int, y: int) -> int:
        return ((x % y) + y) % y
    
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        i = 1
        directions = ((0, 1), (1, 0), (0, -1), (-1, 0))
        d, row, col = 0, 0, 0
        
        while i <= n ** 2:
            ans[row][col] = i
            i += 1
            r = self.floorMod(row + directions[d][0], n)
            c = self.floorMod(col + directions[d][1], n)
            
            if ans[r][c] != 0:
                d = (d + 1) % 4
            row += directions[d][0]
            col += directions[d][1]
        
        return ans
            