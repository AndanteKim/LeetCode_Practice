class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        def could_place(d: int, row: int, col: int) -> None:
            """
            Check if one could place a number d in (row, col) cell
            """
            return not (d in rows[row] or d in columns[col] or\
                       d in boxes[box_index(row, col)])
        
        def place_number(d: int, row: int, col: int) -> None:
            """
            Place a number d in (row, col) cell
            """
            rows[row][d] += 1
            columns[col][d] += 1
            boxes[box_index(row, col)][d] += 1
            board[row][col] = str(d)
        
        def remove_number(d: int, row: int, col: int) -> None:
            """
            Remove a number which didn't lead to a solution
            """
            del rows[row][d]
            del columns[col][d]
            del boxes[box_index(row, col)][d]
            board[row][col] = '.'
        
        def place_next_numbers(row: int, col: int) -> None:
            """
            Call backtrack function in recursion
            to continue to place numbers
            till the moment we have a solution
            """
            
            if col == N - 1 and row == N - 1:
                nonlocal sudoku_solved
                sudoku_solved = True
            
            else:
                if col == N - 1:
                    backtrack(row + 1, 0)
                else:
                    backtrack(row, col + 1)
            
        
        def backtrack(row: int = 0, col: int = 0) -> None:
            if board[row][col] == '.':
                for d in range(1, 10):
                    if could_place(d, row, col):
                        place_number(d, row, col)
                        place_next_numbers(row, col)
                        
                        # If sudoku is solved, then no need to backtrack since there is a single unique solution
                        if not sudoku_solved:
                            remove_number(d, row, col)
            
            else:
                place_next_numbers(row, col)
        
        # box size
        n = 3
        
        # row size
        N = n * n
        
        # lambda function to compute box index
        box_index = lambda row, col: (row // n) * n + col // n
        
        rows = [defaultdict(int) for i in range(N)]
        columns = [defaultdict(int) for i in range(N)]
        boxes = [defaultdict(int) for i in range(N)]
        
        for i in range(N):
            for j in range(N):
                if board[i][j] != '.':
                    d = int(board[i][j])
                    place_number(d, i, j)
                    
        sudoku_solved = False
        backtrack()