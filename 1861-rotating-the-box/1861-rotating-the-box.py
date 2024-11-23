class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        rotated_box = [[""] * m for _ in range(n)]
        
        # Create the transpose of the input grid in 'rotated_box'
        for i in range(n):
            for j in range(m):
                rotated_box[i][j] = box[j][i]
        
        # Reverse each row in the transpose grid to complete the 90° rotation
        for i in range(n):
            rotated_box[i].reverse()
        
        # Apply gravity to let stones fall to the lowest possible empty cell in each column
        for j in range(m):
            # Process each cell in column 'j' from bottom to top
            for i in range(n - 1, -1, -1):
                if rotated_box[i][j] == ".":
                    # Found an empty cell; check if a stone can fall into it
                    next_row_with_stone = -1
                    
                    # Look for a stone directly above the empty cell 'rotated_box[i][j]'
                    for k in range(i - 1, -1, -1):
                        if rotated_box[k][j] == "*":
                            break   # Obstacle blocks any stones above
                        
                        if rotated_box[k][j] == "#":
                            # Stone found with no obstacles in between
                            next_row_with_stone = k
                            break
                    
                    # If a stone was found above, let it fall into the empty cell 'rotated_box[i][j]'
                    if next_row_with_stone != -1:
                        rotated_box[next_row_with_stone][j] = "."
                        rotated_box[i][j] = "#"
                
        return rotated_box