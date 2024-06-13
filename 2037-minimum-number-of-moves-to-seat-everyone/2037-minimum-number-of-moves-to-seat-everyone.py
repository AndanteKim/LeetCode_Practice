class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        # Find the maximum position in the arrays
        max_pos = max(max(seats), max(students))
        
        # Stores difference between number of seats and students at each position
        diff = [0] * max_pos
        
        # Count the available seats at each position
        for pos in seats:
            diff[pos - 1] += 1
        
        # Remove a seat for each student at that position
        for pos in students:
            diff[pos - 1] -= 1
        
        # Calculate the number of moves needed to seat the students
        moves, unmatched = 0, 0
        
        for d in diff:
            moves += abs(unmatched)
            unmatched += d
            
        return moves