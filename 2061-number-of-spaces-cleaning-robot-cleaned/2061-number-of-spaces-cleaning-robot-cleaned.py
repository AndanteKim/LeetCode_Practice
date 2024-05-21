class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        directions = (0, 1, 0, -1, 0)
        rows, cols = len(room), len(room[0])
        cleaned = 0
        
        row, col, direction = 0, 0, 0
        
        # Clean until we revisit a space facing the same direction
        while not room[row][col] >> (direction + 1) & 1:
            # If the robot hasn't cleaned this space yet, increment cleaned
            if room[row][col] == 0:
                cleaned += 1
            
            # Mark the space as visited facing this direction
            room[row][col] |= 1 << (direction + 1)
            
            # Clean the next space straight ahead if it's empty and in the room
            next_row = row + directions[direction]
            next_col = col + directions[direction + 1]
            
            if 0 <= next_row < rows and 0 <= next_col < cols and room[next_row][next_col] != 1:
                row, col = next_row, next_col
                
            # Otherwise turn right and clean the current space
            else:
                direction = (direction + 1) % 4
                
        return cleaned