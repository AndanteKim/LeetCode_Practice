class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = 9
        
        # Use an array to record the status
        rows, cols = [[0] * n for _ in range(n)], [[0] * n for _ in range(n)]
        boxes = [[0] * n for _ in range(n)]
        
        for i in range(n):
            for j in range(n):
                # Check if the position is filled with number
                if board[i][j] == '.':
                    continue
                    
                pos = int(board[i][j]) - 1
                
                # Check the row
                if rows[i][pos] == 1:
                    return False
                rows[i][pos] = 1
                
                # Check the column
                if cols[j][pos] == 1:
                    return False
                cols[j][pos] = 1
                
                # Check the box
                idx = (i // 3) * 3 + j // 3
                if boxes[idx][pos] == 1:
                    return False
                boxes[idx][pos] = 1
                
        return True
                