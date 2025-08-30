class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows, cols = defaultdict(set), defaultdict(set)
        m, n = len(board), len(board[0])

        for i in range(m):
            for j in range(n):
                if board[i][j] != '.':
                    if board[i][j] in rows[i] or board[i][j] in cols[j]:
                        return False
                    rows[i].add(board[i][j])
                    cols[j].add(board[i][j])

        for curr_cube in range(9):
            start_row, start_col, seen = (curr_cube // 3) * 3, (3 * curr_cube) % 9, set()
            for row in range(start_row, start_row + 3):
                for col in range(start_col, start_col + 3):
                    if board[row][col] != '.':
                        if board[row][col] in seen:
                            return False
                        seen.add(board[row][col])

        return True