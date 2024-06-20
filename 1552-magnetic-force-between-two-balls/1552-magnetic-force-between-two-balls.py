class Solution:
    # Check if we can place 'm' balls at 'position'
    # with each ball having at least 'x' gap.
    def can_place_balls(self, x: int, position: List[int], m: int) -> bool:
        # Place the first ball at the first position.
        prev_ball_pos, balls_placed = position[0], 1
        
        # Iterate on each 'position' and place a ball there if we can place it.
        for i in range(1, len(position)):
            curr_pos = position[i]
            # Check if we can place the ball at the current position.
            if curr_pos - prev_ball_pos >= x:
                balls_placed += 1
                prev_ball_pos = curr_pos
            
            # If all 'm' balls are placed, return 'True'.
            if balls_placed == m:
                return True
        
        return False
    
    def maxDistance(self, position: List[int], m: int) -> int:
        ans, n = 0, len(position)
        position.sort()
        
        # Initial search space
        low, high = 1, position[-1] // (m - 1) + 1
        
        while low <= high:
            mid = (low + high) >> 1
            
            # If we can place all balls having a gap at least 'mid',
            if self.can_place_balls(mid, position, m):
                # then 'mid' can be our answer,
                ans = mid
                # and discard the left half search space.
                low = mid + 1
            else:
                # Discard the right half search space.
                high = mid - 1
                
        return ans
