class Solution:
    def feasible(self, piles: List[int], rate: int, h: int) -> bool:
        hoursNeeded = 0
        for pile in piles:
            hoursNeeded += (pile // rate) + 1 if pile / rate != pile // rate else pile // rate
    
        return hoursNeeded <= h
    
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if len(piles) == 1:
            return piles[0] // h + 1 if piles[0] / h != piles[0] // h else piles[0] // h
        
        left, right = 1, max(piles)
        
        while left < right:
            curr_rate = (left + right) >> 1
            
            if self.feasible(piles, curr_rate, h):
                right = curr_rate
            else:
                left = curr_rate + 1
        
        return left