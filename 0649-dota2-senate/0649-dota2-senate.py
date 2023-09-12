class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        # Check senators of each party
        r_count = senate.count('R')
        d_count = len(senate) - r_count
        
        # Floating ban count
        d_ban, r_ban = 0, 0
        
        # Queue of senators
        queue = deque(senate)
        
        # While any party has eligible Senators
        while r_count and d_count:
            # Pop the senator with turn
            curr = queue.popleft()
            
            # If eligible, float the ban on the other party, enqueue again
            # If not, decrement the floating ban and count of the party
            if curr == 'D':
                if d_ban:
                    d_ban -= 1
                    d_count -= 1
                else:
                    r_ban += 1
                    queue.append(curr)
            else:
                if r_ban:
                    r_ban -= 1
                    r_count -= 1
                else:
                    d_ban += 1
                    queue.append(curr)
                    
        return "Radiant" if r_count else "Dire"