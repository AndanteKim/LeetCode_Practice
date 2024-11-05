class Solution:
    def minChanges(self, s: str) -> int:
        # Initialize with first character
        curr_char, consec_cnt = s[0], 0
        min_changes_req = 0
        
        # Iterate through each character
        for ch in s:
            # If current character matches the previous sequence
            if ch == curr_char:
                consec_cnt += 1
                continue
            
            # If we have even count of characters, start new sequence
            if consec_cnt % 2 == 0:
                consec_cnt = 1
            # If odd count, we need to change the current character
            else: 
                consec_cnt = 0
                min_changes_req += 1
            
            # Update the current character for next iteration
            curr_char = ch
            
        return min_changes_req