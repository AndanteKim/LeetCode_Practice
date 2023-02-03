class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        
        n = len(s)
        sections = ceil(n / (2 * numRows - 2.0))
        num_cols = sections * (numRows - 1)
        
        matrix = [[' '] * num_cols for _ in range(numRows)]
        
        curr_row, curr_col = 0, 0
        curr_string_index = 0
        
        
        while curr_string_index < n:
            
            # Move down
            while curr_row < numRows and curr_string_index < n:
                matrix[curr_row][curr_col] = s[curr_string_index]
                curr_row += 1
                curr_string_index += 1
            
            curr_row -= 2
            curr_col += 1
        
            # Move up
            while curr_row > 0 and curr_col < num_cols and curr_string_index < n:
                matrix[curr_row][curr_col] = s[curr_string_index]
                curr_row -= 1
                curr_col += 1
                curr_string_index += 1
        
        answer = ""
        for row in matrix:
            answer += "".join(row)
        
        return answer.replace(" ", "")