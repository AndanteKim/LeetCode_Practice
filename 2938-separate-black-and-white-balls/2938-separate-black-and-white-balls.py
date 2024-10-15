class Solution:
    def minimumSteps(self, s: str) -> int:
        white_pos, ans = 0, 0
        
        # Iterate through each ball in the string
        for curr_pos, ch in enumerate(s):
            if ch == '0':
                # Calculate the number of swaps needed
                ans += curr_pos - white_pos
                
                # Move the next available position for a white ball one step to the right
                white_pos += 1
                
        return ans