class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        if len(time) == 1: return totalTrips * time[0]
        
        l, r = 1, totalTrips * min(time)
        
        while l < r:
            tripCount = 0
            mid = (l + r) >> 1
            for t in time:
                tripCount += (mid // t)
            
            if tripCount >= totalTrips:
                r = mid
            else:
                l = mid + 1
        
        return l