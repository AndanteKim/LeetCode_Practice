class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        Visited = 101
        rows, cols = len(matrix), len(matrix[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        current_direction = 0
        change_direction = 0
        row = col = 0
        result = [matrix[0][0]]
        matrix[0][0] = Visited
        
        while change_direction < 2:
            while True:
                next_row = row + directions[current_direction][0]
                next_col = col + directions[current_direction][1]
                
                if not (0 <= next_row < rows and 0 <= next_col < cols): break
                if matrix[next_row][next_col] == Visited: break
                
                change_direction = 0
                row, col = next_row, next_col
                result.append(matrix[row][col])
                matrix[row][col] = Visited
            
            current_direction = (current_direction + 1) % 4
            change_direction += 1
        return result