class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        count, magnitude, ans = 0, 1, []
        row, col = rStart, cStart
        
        while count < rows * cols:
            # Right
            c = 0
            while c < magnitude and count < rows * cols:
                if 0 <= row < rows and 0 <= col < cols:
                    ans.append([row, col])
                    count += 1
                col += 1
                c += 1
            
            # Down
            r = 0
            while r < magnitude and count < rows * cols:
                if 0 <= row < rows and 0 <= col < cols:
                    ans.append([row, col])
                    count += 1
                row += 1
                r += 1
            magnitude += 1
            
            # Left
            c = 0
            while c < magnitude and count < rows * cols:
                if 0 <= row < rows and 0 <= col < cols:
                    ans.append([row, col])
                    count += 1
                col -= 1
                c += 1
            
            # Up
            r = 0
            while r < magnitude and count < rows * cols:
                if 0 <= row < rows and 0 <= col < cols:
                    ans.append([row, col])
                    count += 1
                row -= 1
                r += 1
                
            magnitude += 1
            
        return ans