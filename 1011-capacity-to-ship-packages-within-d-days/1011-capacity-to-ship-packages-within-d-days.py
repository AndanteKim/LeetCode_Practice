class Solution:
    def feasible(self, weights: List[int], capacity: int, days: int) -> bool:
        daysNeeded, currentLoad = 1, 0
        for weight in weights:
            currentLoad += weight
            if currentLoad > capacity:
                daysNeeded += 1
                currentLoad = weight
        
        return daysNeeded <= days
        
        
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        totalLoad, maxLoad = 0, 0
        for weight in weights:
            totalLoad += weight
            maxLoad = max(maxLoad, weight)
            
        l, r = maxLoad, totalLoad
        
        while l < r:
            mid = (l + r) >> 1
            if self.feasible(weights, mid, days):
                r = mid
            else:
                l = mid + 1
        
        return l