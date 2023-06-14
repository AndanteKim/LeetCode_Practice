class Solution:
    def feasible(self, days: int, bloomDay: List[int], m: int, k: int) -> bool:
        flowers, bouquets = 0, 0
        
        for bloom in bloomDay:
            if bloom > days:
                flowers = 0
            else:
                bouquets += (flowers + 1) // k
                flowers = (flowers + 1) % k
        return bouquets >= m
        
    
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if len(bloomDay) < m * k:
            return -1
        
        left, right = 1, max(bloomDay)
        
        while left < right:
            mid = (left + right) >> 1
            if self.feasible(mid, bloomDay, m, k):
                right = mid
            else:
                left = mid + 1
        return left