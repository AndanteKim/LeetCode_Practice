class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = 9
        # Use binary number to check previous occurrence
        rows, cols, boxes = [0] * n, [0] * n, [0] * n
        
        for i in range(n):
            for j in range(n):
                # Check if the position is filled with number
                if board[i][j] == '.':
                    continue
                    
                pos = int(board[i][j]) - 1
                
                # Check the row
                if rows[i] & (1 << pos):
                    return False
                rows[i] |= (1 << pos)
                
                # Check the col
                if cols[j] & (1 << pos):
                    return False
                cols[j] |= (1 << pos)
                
                # Check the box
                boxes_idx = (i // 3) * 3 + (j // 3)
                
                if boxes[boxes_idx] & (1 << pos):
                    return False
                boxes[boxes_idx] |= (1 << pos)
                    
        return True