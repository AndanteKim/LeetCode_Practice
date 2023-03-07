class Solution:
    def timeEnough(self, time: List[int], given_time: int, totalTrips) -> bool:
        actual_trips = 0
        for t in time:
            actual_trips += given_time // t
        return actual_trips >= totalTrips
    
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        left, right = 1, max(time) * totalTrips
        
        while left < right:
            mid = (left + right) >> 1
            if self.timeEnough(time, mid, totalTrips):
                right = mid
            else:
                left = mid + 1
        
        return left