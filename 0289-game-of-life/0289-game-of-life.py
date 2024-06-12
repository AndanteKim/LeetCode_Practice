class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # Neighbors array to find 8 neighboring cells for a given cell
        neighbors = [(1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1)]
        
        rows, cols = len(board), len(board[0])
        
        # Iterate through board cell by cell.
        for row in range(rows):
            for col in range(cols):
                
                # For each cell count the number of live neighbors
                live_neighbors = 0
                for neighbor in neighbors:
                    # row and column of the neighboring cell
                    r, c = (row + neighbor[0]), (col + neighbor[1])
                    
                    # Check the validity of the neighboring cell and if it was originaally a live cell.
                    if (r < rows and r >= 0) and (c < cols and c >= 0) and abs(board[r][c]) == 1:
                        live_neighbors += 1
                
                # Rule 1 or Rule 3
                if board[row][col] == 1 and (live_neighbors < 2 or live_neighbors > 3):
                    # -1 signifies the cell is not dead, but originally was live.
                    board[row][col] = -1
                    
                # Rule 4
                if board[row][col] == 0 and live_neighbors == 3:
                    # 2 signifieds the cell is now live, but was originally dead.
                    board[row][col] = 2
                    
        # Get the final representation for the newly updated board.
        for row in range(rows):
            for col in range(cols):
                if board[row][col] > 0:
                    board[row][col] = 1
                else:
                    board[row][col] = 0
                    