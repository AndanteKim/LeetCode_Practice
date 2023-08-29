class Solution:
    def bestClosingTime(self, customers: str) -> int:
        # start with closing @ hour 0 and assume the current penalty is 0
        curr_penalty = min_penalty = earliest_hour = 0
        
        for i, ch in enumerate(customers):
            # If status in hour 1 is 'Y', moving it to open hours decrement
            # penalty by 1. Otherwise, moving 'N' to open hours increment penalty by 1
            
            if ch == 'Y':
                curr_penalty -= 1
            else:
                curr_penalty += 1
        
            # Update earliest_hour is a smaller penalty is encountered
            if curr_penalty < min_penalty:
                earliest_hour = i + 1
                min_penalty = curr_penalty
        
        return earliest_hour