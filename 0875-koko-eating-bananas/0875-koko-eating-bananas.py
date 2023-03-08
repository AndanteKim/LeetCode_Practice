class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        left, right = 1, max(piles)
        
        while left < right:
            mid = (left + right) >> 1
            hour_spent = 0
            
            for pile in piles:
                hour_spent += pile // mid + 1 if pile / mid != pile // mid else pile // mid
            
            if hour_spent <= h:
                right = mid
            else:
                left = mid + 1
        
        return right