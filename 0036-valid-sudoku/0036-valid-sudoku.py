class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)
        
        # Use hash set to record the status
        rows, cols, boxes = [set() for _ in range(n)], [set() for _ in range(n)], [set() for _ in range(n)]
        
        for i in range(n):
            for j in range(n):
                val = board[i][j]
                
                # Check if the position is filled with number
                if val == ".":
                    continue
                
                # Check the row
                if val in rows[i]:
                    return False
                rows[i].add(val)
                
                # Check the column
                if val in cols[j]:
                    return False
                cols[j].add(val)
                
                # Check the box
                boxes_i = (i // 3) * 3 + j // 3
                if val in boxes[boxes_i]:
                    return False
                boxes[boxes_i].add(val)
                
        return True
        