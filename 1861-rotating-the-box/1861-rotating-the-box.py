class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        ans = [["."] * m for _ in range(n)]
        
        # Apply gravity to let stones fall to the lowest possible empty cell in each column
        for i in range(m):
            lowest_row_with_empty_cell = n - 1
            
            # Process each cell in row 'i' in reversed order
            for j in range(n - 1, -1, -1):
                # Found a stone - let it fall to the lowest empty cell
                if box[i][j] == "#":
                    # Place it in the correct position in the rotated grid
                    ans[lowest_row_with_empty_cell][m - 1 - i] = "#"
                    lowest_row_with_empty_cell -= 1
                    
                # Found an obstacle - reset 'lowest_row_with_empty_cell' to the row directly above it
                if box[i][j] == "*":
                    # Place the obstacle in the correct position in the rotated grid
                    ans[j][m - 1 - i] = "*"
                    lowest_row_with_empty_cell = j - 1
                    
        return ans