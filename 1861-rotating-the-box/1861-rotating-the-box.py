class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        ans = [[""] * m for _ in range(n)]
        
        # Create the transpose of the input grid in 'result'
        for i in range(m):
            for j in range(n):
                ans[j][i] = box[i][j]
        
        # Reverse each row in the transpose grid to complete the 90° rotation
        for i in range(n):
            ans[i] = ans[i][::-1]
            
        # Apply gravity to let stones fall to the lowest possible empty cell in each column
        for j in range(m):
            lowest_row_with_empty_cell = n - 1
            
            # Process each cell in column 'j' from bottom to top
            for i in range(n - 1, -1, -1):
                # Found a stone - let it fall to the lowest empty cell
                if ans[i][j] == "#":
                    ans[i][j], ans[lowest_row_with_empty_cell][j] = ans[lowest_row_with_empty_cell][j], ans[i][j]
                    lowest_row_with_empty_cell -= 1
                
                # Found an obstacle - reset 'lowest_row_with_empty_cell' to the row directly above it
                if ans[i][j] == "*":
                    lowest_row_with_empty_cell = i - 1
                    
        return ans