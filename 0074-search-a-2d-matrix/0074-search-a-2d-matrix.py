class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row_left, row_right = 0, len(matrix)
        
        while row_left < row_right:
            row_mid = (row_left + row_right) >> 1
            col_left, col_right = 0, len(matrix[0])
            while col_left < col_right:
                col_mid = (col_left + col_right) >> 1
                if matrix[row_mid][col_mid] == target:
                    return True
                if matrix[row_mid][col_mid] < target:
                    col_left = col_mid + 1
                else:
                    col_right = col_mid
            if matrix[row_mid][col_mid] < target:
                row_left = row_mid + 1
            else:
                row_right = row_mid
        
        return False