class Solution:
    def bestClosingTime(self, customers: str) -> int:
        # start with closing at hour 0, the penalty equals all 'Y' in closed hours
        curr_penalty = min_penalty = customers.count('Y')
        earliest_hour = 0
        
        for i, ch in enumerate(customers):
            # If status in hour i is 'Y', moving to open hours decrement
            # penalty by 1. Otherwise, moving 'N' to open hours increment
            # penalty by 1.
            
            if ch == 'Y':
                curr_penalty -= 1
            else:
                curr_penalty += 1
            
            # Update earliest_hour if a smaller penalty is encountered
            if curr_penalty < min_penalty:
                earliest_hour = i + 1
                min_penalty = curr_penalty
        
        return earliest_hour