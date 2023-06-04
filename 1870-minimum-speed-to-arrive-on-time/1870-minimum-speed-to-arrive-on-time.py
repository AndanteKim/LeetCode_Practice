class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        if len(dist) > ceil(hour):
            return -1
        
        left, right = 1, 10 ** 7
        
        while left <= right:
            mid = (left + right) // 2
            time = 0
            
            for i in range(len(dist)):
                time = ceil(time)
                time += dist[i] / mid
            
            if time <= hour:
                right = mid - 1
            else:
                left = mid + 1
        
        return left
        