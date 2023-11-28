class Solution:
    def numberOfWays(self, corridor: str) -> int:
        MOD, count = 1_000_000_007, 1
        
        # Number of seats in current section
        seats = 0
        
        # Tracking index of last S in the previous section
        prev_pair_last = None
        
        # Keep track of seats in the corridor
        for i, thing in enumerate(corridor):
            if thing == "S":
                seats += 1
            
                # If two seats, then this is the last S in the section
                # Update seats for the next section
                if seats == 2:
                    prev_pair_last = i
                    seats = 0
                
                elif seats == 1 and prev_pair_last:
                    count *= i - prev_pair_last
                    count %= MOD
            
        # If odd seats, or zero seats
        if seats == 1 or not prev_pair_last:
            return 0
        
        return count