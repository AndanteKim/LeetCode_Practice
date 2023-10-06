class Solution:
    def is_possible(self, piles: List[int], k: int, h: int) -> bool:
        if k == 0:
            return False
        time = 0
        for pile in piles:
            time += ceil(pile / k)
        return time <= h
    
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 0, 10 ** 9
        
        while left < right:
            mid = (left + right) >> 1
            if self.is_possible(piles, mid, h):
                right = mid
            else:
                left = mid + 1
        return left