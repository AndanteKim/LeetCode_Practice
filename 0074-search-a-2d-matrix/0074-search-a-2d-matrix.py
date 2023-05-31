class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row_left, row_right = 0, len(matrix)
        
        while row_left < row_right:
            row_mid = (row_left + row_right) // 2
            if matrix[row_mid][0] <= target <= matrix[row_mid][-1]:
                col_left, col_right = 0, len(matrix[0])
                while col_left < col_right:
                    col_mid = (col_left + col_right) // 2
                    if matrix[row_mid][col_mid] == target:
                        return True
                    if target < matrix[row_mid][col_mid]:
                        col_right = col_mid
                    else:
                        col_left = col_mid + 1
                
            if target < matrix[row_mid][0]:
                row_right = row_mid
            else:
                row_left = row_mid + 1
            
        return False